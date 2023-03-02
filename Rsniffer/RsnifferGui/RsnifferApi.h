#ifndef RFW_CTRLAPI_H
#define RFW_CTRLAPI_H

/************************************************************
 *   This file provides APIs for the user interface
 *    to communicate with the kernel, and transmits 
 *    the data correspondingly according to the operation
 ************************************************************/

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/socket.h>
#include <errno.h>
#include <iostream> 
#include <string>
#include <fstream> 
#include <sys/time.h>
#include <arpa/inet.h>

#include "../RsnifferTools/RsnifferStruct.h"
#include "../RsnifferTools/RsnifferTool.h"
#include "RsnifferNluser.h"

using namespace std;

Rule rules[MAX_RULE_NUM];
int rnum = 0; //the number of rules

Log logs[MAX_LOG_NUM];
int lnum = 0;//the number of logs

bool Default_flag = false;
unsigned char data[MAX_LEN];

/**
 *  Function related to rules:
 *  add, set up rules and transport rules
**/
bool AddRule(
	const char *src_ip, const char *dst_ip,
	int src_port,
	int dst_port,
    int src_port_end,
	int dst_port_end,
	char protocol,
    bool log) {//Add a new rule to the rule table
	if (rnum < MAX_RULE_NUM) {
		strcpy(rules[rnum].src_ip, src_ip);
		strcpy(rules[rnum].dst_ip, dst_ip);
		rules[rnum].src_port = src_port;
		rules[rnum].dst_port = dst_port;
        rules[rnum].src_port_end = src_port_end;
		rules[rnum].dst_port_end = dst_port_end;
		rules[rnum].protocol = protocol;
        rules[rnum].log = log;
		rnum ++;
		return true;
	}
	return false;
}

bool SendRules(){//Transfer configuration rules to the kernel
    if (Default_flag) {//Add default allow rule
		AddRule("any", "any", -1, -1, -1, -1, -1, 1);
	}
	else AddRule("any", "any", -1, -1, -1, -1, -1, 0);//Add default deny rule

    int sock_fd = netlink_create_socket();
    if (sock_fd == -1) {//Failed to create socket
        perror("Socket error!");
        return false;
    }
    if (netlink_bind_socket(sock_fd) < 0){//Failed to bind address
        perror("Bind error!");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }
    //save the rules into the array and send the data to kernel
    data[0] = SET_RULE;
    data[1] = rnum;
    memcpy(data + 2, rules, rnum * sizeof(Rule));
    netlink_send_message(sock_fd, (const unsigned char *)data, rnum * sizeof(Rule) + 2, 0, 0);
    close(sock_fd);
	rnum --;//delete default rule
    return true;
}

void SetDefault(bool flag){//Set default rule type
    Default_flag = flag;
}

/**
 *  Function related to logs:
 *  get logs from the kernel
**/
bool GetLogs(int cnt){//Get logs from the kernel
    int sock_fd = netlink_create_socket();
    if (sock_fd == -1){//Failed to create socket
        perror("Socket error!\n");
        return false;
    }
    if (netlink_bind_socket(sock_fd) < 0){//Failed to bind socket
        perror("Bind error\n");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }
    //Tell the kernel that the log table needs to be flushed
    unsigned char buff[MAX_LOG_NUM * sizeof(Log)];
    int len;
    data[0] = FLASH_LOGS;
    data[1] = cnt;//Indicates whether the log needs to be emptied
    netlink_send_message(sock_fd, (const unsigned char *)data, 2, 0, 0);
    if (netlink_recv_message(sock_fd, buff, &len)){//receive data
        printf("recvlen:%d\n", len);
        memcpy(logs, buff, len);//write data to log array
        lnum = len / sizeof(Log);//calculate the number of logs
        printf("lnum:%d\n", lnum);
    }
    close(sock_fd);
    return true;
}

char *ParsePacket(int len, unsigned char *data)//parse packetes for network layer, transport and application layer
{
    char *ret = nullptr;
    char str[65536] = {0};
    char tmp[150] = {0};
    int p = 0;
    // Parse IP
    if (data[0] != 0x45)
    {
        ret = "Parse Error: not IP protocol!";
        return ret;
    }
    sprintf(tmp, "[Internet Protocol Version %c] Src: %d.%d.%d.%d, Dst: %d.%d.%d.%d, TTL: %d\n", data[0] / 16 + '0',
        data[12], data[13], data[14], data[15], data[16], data[17], data[18], data[19], data[8]);
    strcpy(str, tmp);
    p = (data[0] % 16) * 4;//length of IP header
    // Parse TCP/UDP/ICMP
    if (data[9] == TCP)
    {
        int srcp, dstp, p1, l, win;
        uint32_t seq;
        uint32_t ack_seq;

        srcp = data[p] * 256 + data[p + 1];
        dstp = data[p + 2] * 256 + data[p + 3];
        seq = data[p + 4] * 256 * 256 * 256 + data[p + 5] * 256 * 256 + data[p + 6] * 256 + data[p + 7];
        ack_seq = data[p + 8] * 256 * 256 * 256 + data[p + 9] * 256 * 256 + data[p + 10] * 256 + data[p + 11];
        p1 = p + data[p + 12] / 16 * 4;//add length of TCP header
        l = len - p1;
        win = data[p + 14] * 256 + data[p + 15];

        sprintf(tmp, "[Transmisson Control Protocol(TCP)] Src Port: %d, Dst Port: %d\n    Seq: %ld, Ack: %ld, Len: %d\n", 
        srcp, dstp, seq, ack_seq, l);
        strcat(str, tmp);
        sprintf(tmp, "    Flags: 0x%x[ ", data[p + 13]);
        if (data[p + 13] & 32)
            strcat(tmp, "urg ");
        if (data[p + 13] & 16)
            strcat(tmp, "ack ");
        if (data[p + 13] & 8)
            strcat(tmp, "psh ");
        if (data[p + 13] & 4)
            strcat(tmp, "rst ");
        if (data[p + 13] & 2)
            strcat(tmp, "syn ");
        if (data[p + 13] & 1)
            strcat(tmp, "fin ");
        strcat(str, tmp);
        sprintf(tmp, "], Window size value:%d\n", win);
        strcat(str, tmp);
        //Parse application layer
        if (data[p + 13] == 0x18 && (srcp == 80 || dstp == 80))//handshake succeeded and the port is matched
            sprintf(tmp, "\n[Hypertext Transfer Protocol(HTTP), len=%d]\n", l);

        else if (srcp == 443 || dstp == 443)
            sprintf(tmp, "\n[SSL/TLS, len=%d]\n", l);
        else
            sprintf(tmp, "\n[Payload, len=%d]\n", l);
        strcat(str, tmp);
        p = strlen(str);
        for (int i = p1; i < len; i ++)
            str[p ++] = (data[i] > 32 && data[i] < 127) ? data[i] : '.';
        str[p] = '\0';
        
    }
    else if (data[9] == UDP)
    {
        int srcp, dstp, l, p1;
        srcp = data[p] * 256 + data[p + 1];
        dstp = data[p + 2] * 256 + data[p + 3];
        l = data[p + 4] * 256 + data[p + 5];
        p1 = p + 8;//add length of UDP header
        sprintf(tmp, "[User Datagram Protocol(UDP)] Src Port: %d, Dst Port: %d, Length: %d\n", srcp, dstp, l);
        strcat(str, tmp);

        if (srcp == 53 || dstp == 53)
            sprintf(tmp, "\n[Domain Name System(DNS), len=%d]\n", len - p1);
        else
            sprintf(tmp, "\n[Payload, len=%d]\n", len - p1);
        strcat(str, tmp);
        p = strlen(str);
        for (int i = p1; i < len; i ++)
            str[p ++] = (data[i] > 32 && data[i] < 127) ? data[i] : '.';
        str[p] = '\0';
    }
    else if (data[9] == ICMP)
    {
        sprintf(tmp, "[Internet Control Message Protocol(ICMP)] type: %d", data[p]);
        if (! data[p])
            strcat(tmp, "[response]\n");
        else if (data[p] == 8)
            strcat(tmp, "[request]\n");
        strcat(str, tmp);
        int p1 = p + 8;

        sprintf(tmp, "\n[Payload, len=%d]\n", len - p1);
        strcat(str, tmp);
        p = strlen(str);
        for (int i = p1; i < len; i ++)
            str[p ++] = (data[i] > 32 && data[i] < 127) ? data[i] : '.';
        str[p] = '\0';
    }
    ret = str;
    return ret;
}

#endif // RFW_CTRLAPI_H
