#include <iostream>
#include <cstdlib>
struct stack_list
{
  int data;
  stack_list * next;
};
void init_stack(stack_list *& s);
bool isEmpty(stack_list * s);
void push(stack_list *&s ,int value);
void pop(stack_list *& s);
void show(stack_list *s);
int main()
{
  stack_list * s;
  init_stack(s);
  push(s,100);
  show(s);
  push(s,199);
  show(s);
  pop(s);
  show(s);
}
void init_stack(stack_list *& s)
{
  s = (stack_list *)malloc(sizeof(stack_list));
  s->data = -1;
  s->next = NULL;
}
bool isEmpty(stack_list * s)
{
  if(s->next==NULL)
    return true;
  return false;
}
void push(stack_list *& s,int value)
{
  stack_list * add = (stack_list *)malloc(sizeof(stack_list));
  add->data=value;
  add->next=s->next;
  s->next = add;
}
void pop(stack_list *&s)
{
  if(isEmpty(s))
  {
    std::cout<<"the stack is empty pop failed"<<std::endl;
    exit(1);
  }
  std::cout<<"the pop data is "<<s->next->data<<std::endl;
  stack_list * temp = s->next;
  s->next = s->next->next;
  free(temp);
}
void show(stack_list * s)
{
  while(s->next != NULL)
  {
    std::cout<<s->next->data<<" ";
    s=s->next;
  }
  std::cout<<std::endl;
}
