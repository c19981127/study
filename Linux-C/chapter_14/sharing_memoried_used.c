//this file we will use sharing memories and writen to it
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/sem.h>
#include "sharing_memories.h"

int main()
{
  int running = 1;
  void *shared_memory = (void *)0;
  struct sharing_memories *shared_stuff;
  char buffer[BUFSIZ];
  int shmid ;

  shmid = shmget((key_t)1234,sizeof(struct sharing_memories),0666|IPC_CREAT);// cteate some sharing_memories
  if(shmid == -1)
  {
    fprintf(stderr,"shmget failed \n");
    exit(EXIT_FAILURE);
  }

  shared_memory = shmat(shmid,(void *)0,0);//make sharing_memories useful
  if(shared_memory == (void *) -1)
  {
    fprintf(stderr,"shmat failed \n");
    exit(EXIT_FAILURE);
  }
  printf("Memori attached at %X \n",(int)shared_memory);

  shared_stuff = (struct sharing_memories *)shared_memory;
  while(running)
  {
    while(shared_stuff->written_by_you == 1) // there is the same problem as before.mark here 
    {
      sleep(1);
      printf("waiting for client.. \n");
    }
    printf("Enter some test :");
    fgets(buffer,BUFSIZ,stdin);

    strncpy(shared_stuff->some_text,buffer,TEXT_SZ);
    shared_stuff->written_by_you =1;
    if(strncmp(buffer,"end",3) == 0)
      return 0;
  }
  if(shmdt(shared_memory) == -1)
  {
    fprintf(stderr, "shmdt failed \n");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
