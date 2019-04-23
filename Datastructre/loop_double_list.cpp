#include <iostream>
#include <cstdlib>
struct loop_double_list
{
  int data;
  struct loop_double_list * pre;
  struct loop_double_list * next;
};
void init_list(loop_double_list * & list);
void show_pre(loop_double_list * list);
void show_next(loop_double_list * list);
int main()
{
  loop_double_list * list;
  init_list(list);
  show_pre(list);
  show_next(list);
}
void init_list(loop_double_list *& list)
{
  list = (loop_double_list *)malloc(sizeof(loop_double_list));
  list->data = 1;
  list->pre = NULL;
  list->next = NULL;
  loop_double_list * temp = list;
  for(int i=1;i<20;i++)
  {
    loop_double_list * test = (loop_double_list *)malloc(sizeof(loop_double_list));
    test->data = i+1;
    test->pre = temp;
    test->next=NULL;
    temp->next = test;
    temp = temp->next;
  }
  temp->next = list;
  list->pre = temp;
}
void show_pre(loop_double_list * list)
{
  loop_double_list * temp = list;
  do
  {
    temp = temp->pre;
    std::cout<<temp->data<<" ";
  } while(temp!=list);
  std::cout<<std::endl;
}
void show_next(loop_double_list * list)
{
  loop_double_list * temp = list;
  do
  {
    std::cout<<temp->data<<" ";
    temp = temp->next;
  } while(temp!=list);
  std::cout<<std::endl;
}
