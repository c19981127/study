#ifndef _FRIEND_CLASS_H_
#define _FRIEND_CLASS_H_
class father
{
private:
  int age;
public:
  friend class son;
  father();
  father(int age_);
  void show () const;
  ~father();
};
class son
{
public:
  void show( const father & t);
};
#endif
