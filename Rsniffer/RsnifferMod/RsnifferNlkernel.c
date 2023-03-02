#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/string.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>
#include <linux/netlink.h>
#include <net/netlink.h>
#include <linux/skbuff.h>
#include "RsnifferNlkernel.h"
#include "../RsnifferTools/RsnifferStruct.h"
#include "../RsnifferTools/RsnifferTool.h"

/******************************************************************************
 *   This file uses netlink to provide functions for passing data from 
 *   the kernel program and the user interface for information exchange
*******************************************************************************/

unsigned char data[MAX_LEN];

extern Rule rules[MAX_RULE_NUM];

extern int rnum; //the number of rules


extern Connection cons[MAX_STATUS_NUM * 3];//the number of connections
extern int cnum;
extern seqlock_t cons_lock;

extern Log logs[MAX_LOG_NUM];
extern int lnum;//the number of logs
extern seqlock_t log_lock;

struct sock *nl_sock = NULL;
/** optional Netlink kernel configuration parameters **/
struct netlink_kernel_cfg nkc = {
	.groups = 0,
	.flags = 0,
	.input = netlink_input, // input callback function
	.cb_mutex = NULL,
	.bind = NULL,
	.compare = NULL
};

/** input function: 
 * It is used to process the data 
 * sent from the user space to the kernel direction, 
 * and call it after receiving the data packet)
**/

void netlink_input(struct sk_buff *ori_skb)//Execute the corresponding operation after receiving the data
{
    unsigned seq;
    if (! ori_skb){//receive nothing
        return;
    }
    struct sk_buff *skb = skb_get(ori_skb);
    if (skb->len < NLMSG_SPACE(0)){//incomplete message header
        return;
    }
    struct nlmsghdr *nlh = nlmsg_hdr(skb);//extract netlink message
    //receive the data and save it into the array
    memset(data, 0, sizeof(data));
    memcpy(data, NLMSG_DATA(nlh), CPY_LEN);

    int i;
    char buff[20], buff2[20];//print debug information
	switch (data[0])//Determine the corresponding operation according to the type
	{
        case SET_RULE:
            //flush rules
            rnum = data[1];
            memcpy(rules, data + 2, rnum * sizeof(Rule));
            for (i = 0; i < rnum; i ++){//print debug information
                printk("Input: \n\n\nrnum:%d", i);
                printk("src_ip:%s dst_ip:%s src_port:%d src_port_end:%d dst_port:%d dst_port_end:%d protocol:%d log:%d\n", 
                    rules[i].src_ip, rules[i].dst_ip, rules[i].src_port, rules[i].src_port_end, rules[i].dst_port, rules[i].dst_port_end, rules[i].protocol, rules[i].log);
            }
            break;
        case FLASH_LOGS:
            //get logs	
            if (data[1] == CLRFLAG)//The log needs to be cleared
            {
                lnum = 0;
                write_seqlock(&log_lock);
                memset(logs, 0, sizeof(logs));
                write_sequnlock(&log_lock);
            }
            do {
                seq = read_seqbegin(&log_lock);
                for (i = 0; i < lnum; i ++){//print debug information
                    printk("Input: \n\n\nlnum:%d", i);
                    printk("access_time:%lld src_ip:%s dst_ip:%s src_port:%hu dst_port:%hu protocol:%hhu length:%hu\n", 
                        logs[i].t, addr_from_net(buff, logs[i].src_ip), addr_from_net(buff2, logs[i].dst_ip), logs[i].src_port, logs[i].dst_port, logs[i].protocol, logs[i].length);
                }
                netlink_send(nlh->nlmsg_pid, (uint8_t *)logs, lnum * sizeof(Log));//send logs to users
                // netlink_send(nlh->nlmsg_pid, (uint8_t *)logs, 42 * sizeof(Log));//send logs to users
            } while (read_seqretry(&log_lock, seq));
            break;
        default:
            break;
	}
    return;
}

void netlink_send(int pid, uint8_t *data, int len)//send reply message(if need) using netlink
{
    struct sk_buff *skb;
    struct nlmsghdr *nlh;
    if (! data || ! nl_sock){//have nothing to send or can`t send
        return;
    }
    skb = alloc_skb(NLMSG_SPACE(len), GFP_KERNEL);//create netlink message(can also use nlmsg_new)
    if (! skb){//Allocate error
        printk(KERN_ERR "alloc_skb error!\n");
        return;
    }
    nlh = nlmsg_put(skb, 0, 0, 0, len, 0);//set message header
    NETLINK_CB(skb).portid = 0;
    NETLINK_CB(skb).dst_group = 0;
    memcpy(NLMSG_DATA(nlh), data, len);//copy the data to send
    netlink_unicast(nl_sock, skb, pid, MSG_DONTWAIT);//send message(to the port ID of user)
}
