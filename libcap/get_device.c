#include <pcap.h>
#include <time.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <net/ethernet.h>
#include <linux/ip.h>
//get ip adress  and umask
void get_ip_mask(const char *device,bpf_u_int32 * netp,bpf_u_int32 *maskp,char *errbuf);
//catch packages
void getPacket(u_char * arg, const struct pcap_pkthdr * pkthdr, const u_char * packet);
void getIP(u_char * packet);
void getUDP(u_char * packet);
int main()
{
  char errbuf[PCAP_ERRBUF_SIZE],*device;
  bpf_u_int32  net =0 ;
  bpf_u_int32  mask = 0;
  device = pcap_lookupdev(errbuf);
  if(device)
  {
    printf("success ! the device is %s \n",device);
  }
  else
  {
    printf("failed! can not get the device \n");
  }

  get_ip_mask(device,&net,&mask,errbuf);

  pcap_t * test = pcap_open_live(device , 65535, 1, 0, errbuf); //here we open the device
  if(!test)
  {
    printf("error pcap_open_live() \n");
    printf("%s \n",errbuf);
    exit(1);
  }
  /*struct bpf_program filter;
  pcap_compile(test,&filter,"dst host 127.0.0.1",1,0);
  pcap_setfilter(test,&filter);*/
  int id = 0;
  pcap_loop(test,1,getPacket,(u_char *)&id);
  pcap_close(test);
  return 0;
}
void get_ip_mask(const char *device ,bpf_u_int32 *netp,bpf_u_int32 *maskp,char * errbuf)
{
  if(pcap_lookupnet(device, netp , maskp, errbuf)!= -1)
    printf("pcap_lookupnet successful \n");
  else
    printf("error, the pcap_lookupnet failed \n");
  struct in_addr add;
  add.s_addr = netp;
  printf("the device is %s \n",device);
  char * net_n = inet_ntoa(add);
  printf("the ip is %s \n",net_n);  //here it does not show as "198.168.1.1" but "1123141"
  add.s_addr = maskp;
  char * mask_n= inet_ntoa(add);
  printf("the mask is %s \n",mask_n);
}
void getPacket(u_char * arg, const struct pcap_pkthdr * pkthdr, const u_char * packet)
{
  int * id = (int *)arg;
  printf("id: %d\n", ++(*id));
  printf("Packet length: %d\n", pkthdr->len);
  printf("Number of bytes: %d\n", pkthdr->caplen);
  printf("Recieved time: %s", ctime((const time_t *)&pkthdr->ts.tv_sec));

  for(int i=0; i<pkthdr->len; ++i)
  {
    printf(" %02x", packet[i]);
    if( (i + 1) % 16 == 0 )
    {
      printf("\n");
    }
  }
  printf("\n\n");

  struct ether_header * ethernet_protocol = (struct ether_header *)packet;  
  unsigned char * p_mac_string = (unsigned char *)ethernet_protocol->ether_shost;  //获取源MAC地址
  printf("Mac Source Address is %02x:%02x:%02x:%02x:%02x:%02x\n",*(p_mac_string+0),*(p_mac_string+1),*(p_mac_string+2),*(p_mac_string+3),*(p_mac_string+4),*(p_mac_string+5));  
  p_mac_string = (unsigned char *)ethernet_protocol->ether_dhost;                  //获取目的MAC地址
  printf("Mac Destination Address is %02x:%02x:%02x:%02x:%02x:%02x\n",*(p_mac_string+0),*(p_mac_string+1),*(p_mac_string+2),*(p_mac_string+3),*(p_mac_string+4),*(p_mac_string+5)); 
  unsigned short ethernet_type = ntohs(ethernet_protocol->ether_type);
  switch(ethernet_type)  
  {  
       case 0x0800:printf("The network layer is IP protocol\n");getIP(packet);break;//ip  
       case 0x0806:printf("The network layer is ARP protocol\n");break;//arp  
       case 0x0835:printf("The network layer is RARP protocol\n");break;//rarp  
       default:printf("The network layer unknow!\n");break;  
  }
}
void getIP(u_char * packet)
{
  struct iphdr * IP = (struct iphdr *)packet;
  __be32 * ip_s = IP->saddr;
  __be32 * ip_d = IP->daddr;
  struct in_addr add;
  add.s_addr = ip_s;
  char * ip_s_n = inet_ntoa(add);
  add.s_addr = ip_d;
  char * ip_d_n = inet_ntoa(add);
  printf("the ip version is : %s \n",IP->ihl);
  printf("the Source IP is %s \n",ip_s_n);
  printf("the Destination IP is %s \n",ip_d_n);
}
void getUDP(u_char * packet)
{
  ;
}