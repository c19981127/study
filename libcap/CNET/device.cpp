#include "device.h"
void get_ip_mask(const char *device ,bpf_u_int32 *netp,bpf_u_int32 *maskp,char * errbuf)
{
  if(pcap_lookupnet(device, netp , maskp, errbuf)!= -1)
    printf("pcap_lookupnet successful \n");
  else
    printf("error, the pcap_lookupnet failed \n");
}
void getPacket(u_char * arg, const struct pcap_pkthdr * pkthdr, const u_char * packet)
{
  char * test = new char [16];
  for(int i=0; i<pkthdr->len; ++i)
  {
    sprintf(test,"%02x", packet[i]);
    comtent = comtent+test+" ";
    if( (i + 1) % 25 == 0 )
    {
      comtent = comtent +"\n";
    }
  }
  comtent = comtent +"\n\n";

  struct ether_header * ethernet_protocol = (struct ether_header *)packet;
  unsigned char * p_mac_string = ( unsigned char *)ethernet_protocol->ether_shost;  //获取源MAC地址
  for(int i =0; i<=5;i++)
  {
    sprintf(test,"%02x",*(p_mac_string+i));
    smac=smac+test;
    if(i!=5)
      smac =smac+" : ";
  }
  smac=smac+"\n";

  //printf("Mac Source Address is %02x:%02x:%02x:%02x:%02x:%02x\n",*(p_mac_string+0),*(p_mac_string+1),*(p_mac_string+2),*(p_mac_string+3),*(p_mac_string+4),*(p_mac_string+5));
  p_mac_string = ( unsigned char *)ethernet_protocol->ether_dhost;
  for(int j =0; j<=5;j++)
  {
    sprintf(test,"%02x",*(p_mac_string+j));
    dmac=dmac+test;
    if(j!= 5)
      dmac = dmac+" : ";
  }
  dmac=dmac+"\n";                  //获取目的MAC地址
  //printf("Mac Destination Address is %02x:%02x:%02x:%02x:%02x:%02x\n",*(p_mac_string+0),*(p_mac_string+1),*(p_mac_string+2),*(p_mac_string+3),*(p_mac_string+4),*(p_mac_string+5));
  unsigned short ethernet_type = ntohs(ethernet_protocol->ether_type);
  type_ = ethernet_type;
  switch(ethernet_type)
  {
       case 0x0800:getIP(packet);break;//ip
       default:break;
  }
  bytes = pkthdr->caplen;
  length = pkthdr->len;
}
void getIP(const u_char * packet)
{
  struct  ip_header * ipr = (struct ip_header *)(packet+14);
  sip = inet_ntoa(ipr->source);
  dip = inet_ntoa(ipr->dest);
}
void getUDP(u_char * packet)
{
  ;
}
