# Rsniffer
## Simple network sniffer based on linux netfilter
### Introduction
The project comes from the topic of network security programming design course of HUST. The project implements a simple network sniffer based on the netfilter architecture, which can intercept data packets and analyze protocols at the network layer, and can set any combination of rules for filtering, also save and reload the interception log at any time for analysis.
### Structure
Rsniffer mainly includes two parts, one is the kernel module(RsnifferMod), and the other is the application program (RsnifferGui, implemented using a graphical interface). The kernel module is used to filter packets according to the rules, and decide whether to intercept and analyze according to the rules; the application program is used to set the rules (write to the kernel module), view the captured packets and display the protocol analysis results, the kernel module and the application The communication of the program is realized through netlink. In addition, there are program files such as the data structure and function used by the kernel module and the application at the same time(implemented in RsnifferTools).
### Notes
1. Application layer filtering can be achieved by combining port numbers and network layer protocols, different application layer protocol analysis and link layer analysis need to be further improved and realized.
2. The connection detection function is realized in the rule filtering, and the design and implementation of the state inspection firewall can be further based on this project.
3. Currently, the preset number of intercepted logs is small. If you want to achieve a more complete dynamic interception function, you should further implement the log dynamic refresh function of the kernel module and use data structures such as vector in the application to support the dynamic growth of the intercepted log storage space.
4. This project is only for learning reference and communication. As the last course design experiment of HUST(CSE), the author also studied with reference to other related implementations(also thanks).
