#ifndef OVERLOAD_H_
#define OVERLOAD_H_
class overload
{
private:
  int age;
public:
  overload();
  overload(int x);
  friend overload & operator+(int x , overload & a);
  overload & operator+(overload & a);
  void show();
  //operator double() const;   there is a problem marking here
  ~overload();
};
#endif
