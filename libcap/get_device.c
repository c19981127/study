#include <pcap.h>
#include <time.h>
//get ip adress  and  umask
void get_ip_mask(const char *device,bpf_u_int32 * netp,bpf_u_int32 *maskp,char *errbuf);
//catch packages
void get_package(pcap_t * device, char * errbuf);
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
  printf("the device is %s \n",device);
  printf("the ip is %u \n",net);  //here it does not show as "198.168.1.1" but "1123141"
  printf("the mask is %u \n",mask);

  pcap_t * test = pcap_open_live(device , 65535, 1, 0, errbuf); //here we open the device
  if(!test)
  {
    printf("error pcap_open_live() \n");
    printf("%s \n",errbuf);
    exit(1);
  }
  get_package(test,errbuf);
  pcap_close(test);
  return 0;
}
void get_ip_mask(const char *device ,bpf_u_int32 *netp,bpf_u_int32 *maskp,char * errbuf)
{
  if(pcap_lookupnet(device, netp , maskp, errbuf)!= -1)
    printf("pcap_lookupnet successful \n");
  else
    printf("error, the pcap_lookupnet failed \n");
}
void get_package(pcap_t * device , char * errbuf)
{
  struct pcap_pkthdr packet;
  const u_char * data = pcap_next(device, &packet);
  if(!data)
  {
    printf("error pacp_next() \n");
    printf("%s \n",errbuf);
    exit(1);
  }
  printf("packet length : %d \n",packet.len);
  printf("number of bytes : %d \n",packet.caplen);
  printf("Recieved time : %s \n",ctime((const time_t *)&packet.ts.tv_sec));
}
