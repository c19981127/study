#ifndef DEVICE_H
#define DEVICE_H
#include <pcap.h>
#include <time.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <net/ethernet.h>
#include <linux/ip.h>
#include "mainwindow.h"
#include <iostream>
using namespace std;
struct ip_header
{
#ifdef WORDS_BIGENDIAN
    u_int8_t ip_version:4,
        ip_header_length:4;
#else
    u_int8_t ip_header_length:4,
         ip_version:4;
#endif
    u_int8_t ip_tos;      /*type of service */
    u_int16_t ip_length;    /*length */
    u_int16_t ip_id;    /*identity */
    u_int16_t ip_off;    /* offset */
    u_int8_t ip_ttl;    /*time to live*/
    u_int8_t ip_protocol;    /* type of protocol*/
    u_int16_t ip_chechsum;  /* chechsum */
    struct in_addr source;
    struct in_addr dest;
};
//get ip adress  and umask
extern int bytes;
extern int length;
extern string sip,dip,smac,dmac,mask_m,comtent;
extern unsigned short type_;
void get_ip_mask(const char *device,bpf_u_int32 * netp,bpf_u_int32 *maskp,char *errbuf);
//catch packages
void getPacket(u_char * arg, const struct pcap_pkthdr * pkthdr, const u_char * packet);
void getIP(const u_char * packet);
void getUDP(u_char * packet);
#endif // DEVICE_H
