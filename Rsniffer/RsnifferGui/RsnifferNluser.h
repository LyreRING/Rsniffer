/******************************************************************************
 *   This file uses netlink to provide functions for passing data from 
 *   the user interface to the kernel program for information exchange
 ******************************************************************************/

//related to netlink
#define NETLINK_TEST (25)
#define N_PID getpid()  //pid when use netlink

int netlink_create_socket(void){//Create netlink socket
    //create a socket
    return socket(AF_NETLINK, SOCK_RAW, NETLINK_TEST);
}

int netlink_bind_socket(int sock_fd){//bind local address
    struct sockaddr_nl local; //netlink communication address
    memset(&local, 0, sizeof(struct sockaddr_nl));
    local.nl_family = AF_NETLINK;
    local.nl_pid = N_PID;//port ID
    local.nl_groups = 0;
    return bind(sock_fd, (struct sockaddr *)&local, sizeof(local));
}

bool netlink_send_message(
    int sock_fd, const unsigned char *buff, 
    int len, unsigned int pid, unsigned int group){//Send messages to the kernel using netlink
    if(! buff) {//have nothing to send
        return false;
    }

    //create netlink message header
    struct nlmsghdr *nlh = NULL;//netlink header
    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(len));
    if(! nlh) {//failed to create header
        perror("Malloc error!");
        return false;
    }
    nlh->nlmsg_len = NLMSG_SPACE(len);//length of message including header
    nlh->nlmsg_pid = N_PID;//sending process port ID
    nlh->nlmsg_flags = 0;//Additional flags
    memcpy(NLMSG_DATA(nlh), buff, len);//set message data part

/** 
 * You can use "sendmsg" and "recvmsg" to transmit iovec-structured data groups, 
 * or you can directly use "sendto" and "recvfrom" standard socket APIs 
 * for data transmission
 **/

    //set scatter/gather array items
    struct iovec iov;
    iov.iov_base = (void *)nlh;//starting address of buffer
    iov.iov_len = nlh->nlmsg_len;//length of buffer

    //set remote address
    struct sockaddr_nl remote;
    memset(&remote, 0, sizeof(struct sockaddr_nl));
    remote.nl_family = AF_NETLINK;
    remote.nl_pid = pid;
    remote.nl_groups = group;

    //set message header to be sent
    struct msghdr msg;
    memset(&msg, 0, sizeof(msg));
    msg.msg_name = (void *)&remote;//optional address
    msg.msg_namelen = sizeof(struct sockaddr_nl);//size of address
    msg.msg_iov = &iov;//scatter/gather array
    msg.msg_iovlen = 1;//elements in msg_iov
    //send message
    if (sendmsg(sock_fd, &msg, 0) < 0)//failed to send
    {
        free(nlh);
        perror("send error!\n");
        return false;
    }
    free(nlh);
    return true;
}

bool netlink_recv_message(int sock_fd, unsigned char *buff, int *len){//Receive kernel reply messages using netlink
    if (! buff || ! len) {//receive buffer parameter exception
        return false;
    }

    //create netlink message header
    struct nlmsghdr *nlh = NULL;
    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_LEN));
    if(! nlh) {//failed to create header
        perror("Malloc error!\n");
        return false;
    }

    //set scatter/gather array items
    struct iovec iov;
    iov.iov_base = (void *)nlh;
    iov.iov_len = NLMSG_SPACE(MAX_LEN);
    //fprintf(stderr, "MAX_LEN: %lld\n", MAX_LEN);
    
    //set message header to be sent
    struct sockaddr_nl remote;
    memset(&remote, 0, sizeof(struct sockaddr_nl));
    struct msghdr msg;
    memset(&msg, 0, sizeof(struct msghdr));
    msg.msg_name = (void *)&remote;
    msg.msg_namelen = sizeof(struct sockaddr_nl);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;
    //receive message
    if (recvmsg(sock_fd, &msg, 0) < 0){//failed to send
        perror("Recvmsg error!\n");
        return false;
    }
    *len = nlh->nlmsg_len - NLMSG_SPACE(0);//get the length of buffer
    memcpy(buff, (unsigned char *)NLMSG_DATA(nlh), *len);
    free(nlh);
    return true;
}