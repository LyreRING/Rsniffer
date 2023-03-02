#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/skbuff.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <net/ip.h>
#include <linux/string.h>
#include <linux/icmp.h>
#include <linux/jiffies.h>
#include <linux/vmalloc.h>
#include <linux/types.h>
#include <linux/spinlock.h>
#include <linux/seqlock.h>
#include <linux/time.h>
#include <linux/timex.h>
#include <linux/rtc.h>
#include <linux/ctype.h>

#include "../RsnifferTools/RsnifferStruct.h"
#include "../RsnifferTools/RsnifferTool.h"
#include "RsnifferNlkernel.h" 

//#define printk(fmt, ...) do {} while(0)
/****************************************************************************************************************************
 *   This file is a kernel module program, which mainly uses the linux netfilter architecture 
 *	to filter the data packets, performs different processing on the data packets according to 
 *	the state detection results and rule matching.
 ****************************************************************************************************************************/
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Lyre");

Rule rules[MAX_RULE_NUM];
int rnum = 0; //the number of rules                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    

Connection cons[MAX_STATUS_NUM * 3];//the number of connections
int cnum = 0;
// Protect status table and hash table
DEFINE_SEQLOCK(cons_lock);

Log logs[MAX_LOG_NUM];
int lnum = 0;//the number of logs
// Protect access log array
DEFINE_SEQLOCK(log_lock);

/* Define functions when intercepting the packets */
unsigned int hook_func(unsigned int,struct sk_buff *,const struct net_device *,
        const struct net_device *,int(*okfn)(struct sk_buff*));//perform packet filtering

static struct nf_hook_ops input_filter = {
	.hook = (nf_hookfn *)hook_func,
	.pf = PF_INET,
	.hooknum = NF_INET_LOCAL_IN,
	.priority = NF_IP_PRI_FIRST
};   // NF_INET_LOCAL_IN - for incoming packets
static struct nf_hook_ops output_filter = {
	.hook = (nf_hookfn *)hook_func,
	.pf = PF_INET,
	.hooknum = NF_INET_LOCAL_OUT,
	.priority = NF_IP_PRI_FIRST
};   // NF_INET_LOCAL_OUT - for outgoing packets
static struct nf_hook_ops forward_filter = {
	.hook = (nf_hookfn *)hook_func,
	.pf = PF_INET,
	.hooknum = NF_INET_FORWARD,
	.priority = NF_IP_PRI_FIRST
};   // NF_INET_FORWARD - for packets to be forwarded

/**
 * Status Maintenance Section:
 * Defines functions related to state detection, updating and inserting new states, 
 * which are implemented by modifying and querying the HASH table
 **/

typedef long long ll;
ll head[MAX_STATUS_NUM + 5];//hash chain head
ll nxt[MAX_STATUS_NUM * 3];//The next element number of the element in the hash chain
ll s_index = 1;//The number of elements in the hash table

/*
  define timeout: generally set to 10s, virtual connection timeout is relatively short
  define connection status: abnormal state/no free connection insertion location/connection exists
 */
#define DELAY (jiffies + 8 * HZ) 
#define SHORT_DELAY (jiffies + 3 * HZ) 
#define ERROR_STATUS -1
#define NON_EXIST 0
#define EXIST -2 

int status_check(unsigned src_ip, unsigned dst_ip, unsigned char protocol,
	unsigned short src_port, unsigned short dst_port, struct sk_buff * skb){//Detect if state already exists or ready to insert
	unsigned hash = (src_ip ^ dst_ip ^ protocol ^ src_port ^ dst_port) % MAX_STATUS_NUM;//get the hash value
	ll i;
	unsigned seq;
	//State detection according to different protocol types
	do {
		seq = read_seqbegin(&cons_lock);
		for (i = head[hash]; i; i = nxt[i]) { //Check if state exists
			if (time_before(jiffies, cons[i].delay)) { //Check for connections that are not currently timing out`
				if (cons[i].src_ip == src_ip && cons[i].dst_ip == dst_ip && cons[i].src_port == src_port && cons[i].dst_port == dst_port)
				{//Connections in the same or opposite direction 
					//No timeout, reset delay, feedback status exists
					if (read_seqretry(&cons_lock, seq))
						continue;

					read_seqlock_excl(&cons_lock);
					if (protocol == TCP)
						cons[i].delay = DELAY;
					else
						cons[i].delay = SHORT_DELAY;
					read_sequnlock_excl(&cons_lock);
					return EXIST;
				}		
			}
			else//Reuse a timed out connection	
				return i;
		}
	} while (read_seqretry(&cons_lock, seq));

	struct iphdr *iph = ip_hdr(skb);
	if (protocol == TCP)//If there is no TCP connection
		if (((struct tcphdr *)(skb->data + (iph->ihl * 4)))->rst)//it must be a syn packet
			return ERROR_STATUS;
		else 
			return NON_EXIST;
	if (protocol == UDP)//Establish a virtual connection for UDP
		return NON_EXIST;
	if (protocol == ICMP)//If there is no TCP connection
		if (! ((struct icmphdr *)(skb->data + (iph->ihl * 4)))->type)//it shouldn`t be a echo-reply packet
			return ERROR_STATUS;
		else
			return NON_EXIST;
	return NON_EXIST;
}	

void status_insert(unsigned src_ip, unsigned dst_ip, unsigned char protocol,
	unsigned short src_port, unsigned short dst_port, unsigned p){//Insert a new connection in hash table
	write_seqlock(&cons_lock); // lock (avoid to be modified by multiple processes or threads)
	if (p == NON_EXIST)//Insert a new connection to the hash table header
	{
		if (s_index >= MAX_STATUS_NUM * 3)
		{
			write_sequnlock(&cons_lock); // unlock
			return;  //The hash table is full and will not be inserted for the time being
		}
		p = s_index;
		unsigned hash = (src_ip ^ dst_ip ^ protocol ^ src_port ^ dst_port) % MAX_STATUS_NUM;	 
		nxt[p] = head[hash], head[hash] = p, s_index ++;//insert at the beginning of the chain
	}
	//modify the parameters(of an existing connection)
	cons[p].src_ip = src_ip;
	cons[p].dst_ip = dst_ip;
	cons[p].src_port = src_port;
	cons[p].dst_port = dst_port;
	cons[p].protocol = protocol;
	if (protocol == TCP)
		cons[p].delay = DELAY;
	else
		cons[p].delay = SHORT_DELAY;
	write_sequnlock(&cons_lock); // unlock
}

/**
 * Hook Function Section:
 * Defines the functions related to rule matching and NAT conversion when intercepting packets, 
 * and includes some tool functions for obtaining port information and IP matching required in the process
 **/

void port_get(struct sk_buff *skb, struct iphdr *iph, unsigned short *src_port, unsigned short *dst_port){//Get the port number of the packet
	struct tcphdr *tcph;
	struct udphdr *udph;
	switch(iph->protocol){
		case TCP://The header needs to be obtained when the protocol is TCP or UDP
			printk("TCP packet\n");
			tcph = (struct tcphdr *)(skb->data + (iph->ihl * 4));
			*src_port = ntohs(tcph->source);
			*dst_port = ntohs(tcph->dest);
			break;
		case UDP:
			printk("UDP packet\n");
			udph = (struct udphdr *)(skb->data + (iph->ihl * 4));
			*src_port = ntohs(udph->source);
			*dst_port = ntohs(udph->dest);
			break;
		default://ignores ports when protocol is ICMP
			printk("ICMP or UNKNOW PROTOCOL: %d\n", iph->protocol);
			*src_port = 0;
			*dst_port = 0;
			break;
	}
}

bool ip_match(unsigned ip, const char *ip_range){//Compare whether the packet IP is in the corresponding network segment
	unsigned t_ip = 0, mask = 0xFFFFFFFF;
	netseg_convert(&t_ip, &mask, ip_range);//Convert network segment to IP and mask
    return (t_ip & mask) == (ip & mask);
}

bool rule_match(Rule t_rule, struct iphdr *iph, short src_port, short dst_port){//Check whether the packet information matches the firewall rules
	//Match IP, if IP rule is not 'ANY', then do not match if not consistent
	if (strcmp(t_rule.src_ip, "any") && ! ip_match(ntohl(iph->saddr), t_rule.src_ip)) 
		return false;
	if (strcmp(t_rule.dst_ip, "any") && ! ip_match(ntohl(iph->daddr), t_rule.dst_ip)) 
		return false;
	//Match protocol, if protocol rule is not 'ANY', then do not match if not consistent
	if (t_rule.protocol != ANY && t_rule.protocol != iph->protocol) 
		return false;
	else if (t_rule.protocol != ICMP){//When the protocol matches, the port will be ignored
	//Match port, if port rule is not 'ANY', then do not match if not consistent
		if (t_rule.src_port != ANY && (src_port < t_rule.src_port || src_port > t_rule.src_port_end))
			return false;
		if (t_rule.dst_port != ANY && (dst_port < t_rule.dst_port || dst_port > t_rule.dst_port_end)) 
			return false;
	}
	return true;
}

void log_write(struct sk_buff *skb, short src_port, short dst_port)
{
    //write log
	struct iphdr *iph = ip_hdr(skb);
	char test_buf[1550];
	struct sk_buff *skb_iter;
	skb_frag_t *skb_frag_iter;
	struct page *frag_page_iter;
	u8 *frag_page_data;
	int copied_len = 0;
	int printable_count = 0;
	int i;

	write_seqlock(&log_lock);
	if(lnum < MAX_LOG_NUM){
		logs[lnum].t = ktime_get_real_seconds();//Get the time of the intercepted packet
		logs[lnum].src_ip = iph->saddr;
		logs[lnum].dst_ip = iph->daddr;
		logs[lnum].dst_port = dst_port;
		logs[lnum].src_port = src_port;
		logs[lnum].protocol = iph->protocol;
		logs[lnum].length = skb->len;

		// Access data in the sk_buff
		if (skb_is_nonlinear(skb)) {
			printk("log write: This packet is nonlinear");
			memcpy(logs[lnum].data, skb->data, skb_headlen(skb));
			copied_len += skb_headlen(skb);
			if (skb_has_frag_list(skb)) {
				// Access data from the frag_list (skb->next)
				skb_walk_frags(skb, skb_iter) {
					/// FIXME: Unconfirmed
					memcpy(logs[lnum].data + copied_len, skb_iter->data, skb_iter->len);
					copied_len += skb_iter->len;
				}
			}
			else {
				// Access data from unpaged fragments
				// We suppose there is up to one extra page in the frags array
				if (skb_shinfo(skb)->nr_frags == 1) {
					skb_frag_ref(skb, 0);
					frag_page_iter = skb_frag_page(&skb_shinfo(skb)->frags[0]);
					frag_page_data = kmap_local_page(frag_page_iter);
					memcpy(logs[lnum].data + skb_headlen(skb), frag_page_data, skb->data_len);
					kunmap_local(frag_page_data);
					skb_frag_unref(skb, 0);
				}
			}
		}
		else {
			memcpy(logs[lnum].data, skb->data, skb->len);
		}
		lnum ++;
	}
	write_sequnlock(&log_lock); 
}

unsigned int hook_func(unsigned int hooknum, struct sk_buff *skb, const struct net_device *in,
    const struct net_device *out, int(*okfn)(struct sk_buff*)){//Process packets according to the status in the hash table and firewall rules
	int ret, i;
	short src_port, dst_port;
	struct iphdr *iph;// ip header
	iph = ip_hdr(skb);
	
	//get port information
	port_get(skb, iph, &src_port, &dst_port);
	//status list
	ret = status_check(iph->saddr, iph->daddr, iph->protocol, src_port, dst_port, skb);//Get status detection results
	if (ret == EXIST)//If the connection exists, let the packet pass normally
	{
		printk(("Exist!\n"));
		log_write(skb, src_port, dst_port);
		return NF_ACCEPT;
	}
	if (ret == ERROR_STATUS)
	{
		printk(("Error status!\n"));
		return NF_ACCEPT;
	}

	//rules matching
	for(i = 0; i < rnum; i ++){//Determine whether a new connection needs to be established for the packet according to the rules
		//printk("matching the %dth rules......\n", i);
		if (! rule_match(rules[i], iph, src_port, dst_port))//This rule does not match, try to match the next one
			continue;
		if(rules[i].log){//when accept, record the status
			status_insert(iph->saddr, iph->daddr, iph->protocol, src_port, dst_port, ret);
			printk("insert the %dth connection\n", ret);
			log_write(skb, src_port, dst_port);
    		return NF_ACCEPT;
		}
		else return NF_ACCEPT;
	}
	//Allow pass when initialized without rules
	status_insert(iph->saddr, iph->daddr, iph->protocol, src_port, dst_port, ret);
	printk("insert the %dth connection\n", ret);
    return NF_ACCEPT;
}

/**
 * Initialization and Cleanup Section:
 * Defines the operations such as device creation, netlink creation and function registration 
 * that need to be performed when the module is loaded, and the corresponding cleanup operations
 * when the module is unloaded
 **/
static int RINGfirewall_init(void){//Register netfilter functions when the module is loaded
	printk("RINGfirewall init...\n");
	
	/* Hook function registration */
	nf_register_net_hook(&init_net, &input_filter);
	nf_register_net_hook(&init_net, &output_filter);
	nf_register_net_hook(&init_net, &forward_filter);

	/* Netlink initialization */
	nl_sock = netlink_kernel_create(&init_net, NETLINK_TEST, &nkc);
	if (! nl_sock) {
		printk(KERN_ERR "Create netlink socket error!\n");
		return -1;
	}
	else 
		printk(KERN_ALERT "Netlink init success!\n");

	return 0;
}

static void RINGfirewall_exit(void){//Finishing work when the module exits
	printk("RINGfirewall exit...\n");
	
	/* unregister operation, etc. */
	nf_unregister_net_hook(&init_net, &input_filter);
	nf_unregister_net_hook(&init_net, &output_filter);
	nf_unregister_net_hook(&init_net, &forward_filter);
	netlink_kernel_release(nl_sock);
}

module_init(RINGfirewall_init);
module_exit(RINGfirewall_exit);
