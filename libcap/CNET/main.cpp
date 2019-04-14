#include "mainwindow.cpp"
#include <QApplication>
#include "device.cpp"
#include <string>
using namespace std;
string sip,dip,smac,dmac,mask_m,comtent;
int length ,bytes;
unsigned short type_;
bool count_x = true;
void set(main_window & mainwindow);
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    main_window mainwindow;
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
    do
    {
     int id = 0;
     count_x=false;
     pcap_loop(test,1,getPacket,(u_char *)&id);
     set(mainwindow);
     mainwindow.show();
     app.exec();
     smac = "";
     dmac = "";
    }while(count_x);
    
    pcap_close(test);
}
void set(main_window & mainwindow)
{

    switch(type_)
    {
       case 0x0800:mainwindow.set_type("IP");break;//ip
       case 0x0806:mainwindow.set_type("ARP");break;//arp
       case 0x0835:mainwindow.set_type("RARP");break;//rarp
       default:mainwindow.set_type("unknow");break;
    }
    mainwindow.set_bytes(bytes);
    mainwindow.set_length(length);
    mainwindow.set_src(QString::fromStdString(sip));
    mainwindow.set_mask(QString::fromStdString(mask_m));
    mainwindow.set_SMac(QString::fromStdString(smac));
    mainwindow.set_DMac(QString::fromStdString(dmac));
    mainwindow.set_src(QString::fromStdString(sip));
    mainwindow.set_dst(QString::fromStdString(dip));
    mainwindow.set_comtent(QString::fromStdString(comtent));
}