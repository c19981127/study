#include <iostream>
#include <cstdlib>
struct list_queue
{
  int data;
  list_queue * next;
};
bool isEmpty(list_queue * list);
//bool isFull(list_queue * list);  because of list,never full
void init(list_queue * &list);
void push(list_queue * list,int value);
void pop(list_queue * &list);
void show(list_queue * list);
int main()
{
  list_queue * list;
  init(list);
  for(int i=1;i<10;i++)
    push(list,i*100);
  show(list);
  for(int i=0;i<5;i++)
    pop(list);
  show(list);
}
bool isEmpty(list_queue * list)
{
  if(list->next == NULL);
    return true;
  return false;
}
void init(list_queue * &list)
{
  list = (list_queue *)malloc(sizeof(list_queue));
  list->data = -1;
  list->next = NULL;
}
void push(list_queue * list ,int value)
{
  list_queue * temp = list;
  for(;temp->next!=NULL;temp=temp->next)
  {
    ;
  }
  list_queue * add = (list_queue *)malloc(sizeof(list_queue));
  add->data = value;
  add->next=NULL;
  temp->next = add;
}
void pop(list_queue * & list)
{
  /*if(isEmpty(list))
  {
    std::cout<<"the queue is Empty pop failed"<<std::endl;
    exit(1);
  }*/
  list=list->next;
}
void show(list_queue * list)
{
  list_queue * temp = list->next;
  for(;temp!=NULL;temp=temp->next)
  {
    std::cout<<temp->data<<std::endl;
  }
}
