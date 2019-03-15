#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <unistd.h>

int main()
{
  int socket_fd;
  int len;
  struct sockaddr_un address;
  int result;
  char ch='A';
  //create a socket
  socket_fd = socket(AF_UNIX,SOCK_STREAM,0);
  //rename the socket due to the server\
  address.sun_family = AF_UNIX;
  strcpy(address.sun_path,"server_socket");
  len = sizeof(address);

  //connect the socket to the server
  result = connect(socket_fd, (struct sockaddr *)&address, len);
  if(result == 0)   //this is a mark which means there is a problem
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
