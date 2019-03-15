#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
  int socket_fd,len;
  struct sockaddr_in address;
  int result;
  char ch = 'A';

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = 9734;
  len = sizeof(address);

  result = connect(socket_fd, (struct sockaddr *)&address, len);
  if(result == 0)
  {
    perror("oops: client1");
    exit(1);
  }
  write(socket_fd,&ch,1);
  read(socket_fd , &ch ,1);
  printf("%c \n",ch);
  close(socket_fd);
  exit(0);
}
