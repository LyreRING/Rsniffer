/******************************************************************************
 *   This file provides some utility functions such as address translation
 ******************************************************************************/

static unsigned addr_to_num(const char *ip_str){//Convert IP address string to integer
    int cnt = 0, i;
    int len = strlen(ip_str);
    unsigned tmp = 0, ip = 0;
    for(i = 0; i < len; i++){
        if(ip_str[i] == '.'){
            ip = ip | (tmp << (24 - cnt));
            tmp = 0;
            cnt += 8;
            continue;
        }
        tmp *= 10;
        tmp += ip_str[i] - '0';
    }
    ip = ip | tmp;
    return ip;
}

static char *addr_from_net(char *buff, __be32 addr){//Convert network byte order IP address to string
    __u8 *p = (__u8*)&addr;
    snprintf(buff, 16, "%u.%u.%u.%u",
        (__u32)p[0], (__u32)p[1], (__u32)p[2], (__u32)p[3]);
    return buff;
}

static void netseg_convert(unsigned *ip, unsigned *msk, const char *ip_range){//convert network segment to network number and mask
    char r_ip[20];
	unsigned lnet = 0, t_ip = 0;
    strcpy(r_ip, ip_range);
	int len = strlen(r_ip), i;
	int pos = len;
    for(i = 0; i < len; i ++){
        if(pos != len){//get network address length
            lnet *= 10;
            lnet += r_ip[i] - '0';
        }
        else if(r_ip[i] == '/')
            pos = i;
    }
    r_ip[pos] = '\0';
	unsigned mask = 0xFFFFFFFF;
    if(lnet)//get mask
        mask <<= (32 - lnet);
    t_ip = addr_to_num(r_ip);
    *ip = t_ip, *msk = mask; 
}

static void port_split(const char *port_range, int *port, int *port_end){//Get the port start and end values from the input port range
   int len = strlen(port_range);
   if (! strcmp(port_range, "any"))//port is set to any
   {
        *port = *port_end = ANY;
        return;
   }
   if (! strcmp(port_range, "null"))//ignore port number
   {
        *port = *port_end = 0;
        return;
   }
   int i, lft = 0, rgt = 0, rflag = 0;
   for (i = 0; i < len; i ++)
   {
        if (port_range[i] >= '0' && port_range[i] <= '9')
            rgt = rgt * 10 + port_range[i] - '0';
        else if (port_range[i] == '-')
        {   
            rflag = 1;
            lft = rgt;
            rgt = 0;
        }
   }
   if (rflag)//The input port is a range not a single value
   {
        *port = lft, *port_end = rgt;
        return;
   }
   else
        *port = *port_end = rgt;
    return;
}

static void port_merge(int port, int port_end, char *buff){//Combine the start and end values of port into a port range
    if (port == ANY)
        snprintf(buff, 20, "any");
    else if ((! port) && (! port_end))
        snprintf(buff, 20, "null");
    else if (port == port_end)
        snprintf(buff, 20, "%d", port);
    else
        snprintf(buff, 20, "%d-%d", port, port_end);
    return;
}