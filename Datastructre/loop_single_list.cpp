#include <iostream>
#include <cstdlib>
struct loop_single_list
{
  int data;
  loop_single_list * next;
};
//the point is same as single list but there  is something  different
void init_list(loop_single_list * &list);
void show(loop_single_list * list);
int main()
{
  loop_single_list * list;
  init_list(list);
  show(list);
}
void init_list(loop_single_list * &list)
{
  list = (loop_single_list *)malloc(sizeof(loop_single_list));
  loop_single_list * test = list;
  list->data = 1;
  list->next = test;
  for(int i=1;i<10;i++)
  {
    loop_single_list * temp = (loop_single_list *)malloc(sizeof(loop_single_list));
    temp->data =i+1;
    test->next = temp;
    temp->next = list;
    test = test->next;
  }
}
void show(loop_single_list * list)
{
  loop_single_list * temp = list;
  do
  {
      std::cout<<temp->data<<" ";
      temp = temp->next;
  } while(temp != list);
  std::cout<<std::endl;
}
