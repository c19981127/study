// we use this file to recive from  queue
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
struct my_message
{
  long int my_message_type;
  char some_text[BUFSIZ];
};
int main()
{
  int running = 1;
  int msgid ;
  struct my_message some_data;
  long int message_to_recive = 0;

  msgid = msgget((key_t)1234,0666|IPC_CREAT);
  if(msgid == -1)
  {
    fprintf(stderr, "message failed with error\n");
    exit(EXIT_FAILURE);
  }
  while(running)
  {
    if(msgrcv(msgid,(void *)&some_data,BUFSIZ,message_to_recive,0 )== -1)
    {
      fprintf(stderr, "msgrcv failed with error\n");
      exit(EXIT_FAILURE);
    }
    printf("You wrote : %s",some_data.some_text);
    if(strncmp(some_data.some_text,"end",3) == 0) //srencp return 0 if equal ,return 1 otherwise
      running = 0;
  }
  if(msgctl(msgid,IPC_RMID,0) == -1)
  {
    fprintf(stderr, "msgctl failed with error\n");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
