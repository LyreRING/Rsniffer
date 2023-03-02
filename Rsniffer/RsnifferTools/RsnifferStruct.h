/*******************************************************************************
 *   This file defines structures and macros for recording rules, states, etc.
 *******************************************************************************/

//network protocol number
#define TCP 6
#define UDP 17
#define ICMP 1
#define ANY -1

//The number of members of each structure
#define MAX_RULE_NUM 1024
#define MAX_STATUS_NUM 1001
#define MAX_LOG_NUM 1024

//The type of message passed into the kernel
#define SET_RULE 0
#define FLASH_LOGS 1

/** 
 * array of passed data(0):
 * element 0 represents the data type, 
 * element 1 represents the corresponding quantity, 
 * and the data content is stored later
**/
#define MAX_LEN (2097152) //data_len

//structure of rule table
typedef struct {
    char src_ip[20];
    char dst_ip[20];
    int src_port;
    int dst_port;
    int src_port_end;
    int dst_port_end;
    char protocol;
    bool log;
}Rule;

//structure of status table
typedef struct {
    unsigned src_ip;
    unsigned dst_ip;
    unsigned short src_port;
    unsigned short dst_port;
    unsigned char protocol;
    unsigned long delay;
}Connection;

//structure of log table
typedef struct {
    long long t;
    unsigned src_ip;
    unsigned dst_ip;
    unsigned short src_port;
    unsigned short dst_port;
    unsigned char protocol;
    unsigned short length;
    unsigned char data[1550];
}Log;
