/***************************************************************************************
 *   This file defines the function to be called when transferring data using netlink
****************************************************************************************/
#define NETLINK_TEST (25)

extern struct sock *nl_sock;
#define CPY_LEN 1000
#define CLRFLAG 0

extern struct netlink_kernel_cfg nkc;

void netlink_input(struct sk_buff *__skb);

void netlink_send(int pid, uint8_t *data, int len);
