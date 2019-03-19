#include <iostream>
#include <fstream>
int main()
{
  std::cout.put(65).put(97)<<std::endl; //std::cout.put() return class cout and then become cout.put(97)
  long val = 123131313;
  std::cout.write((char*) & val ,sizeof(long));//4 字节的long 直 作为独立的4个字节传输
  char vaa = 'a';
  std::cout.write(&vaa,sizeof(char))<<std::endl;

  std::ofstream fout;
  fout.open("test.txt");            //fout does not need nake sure  the file has been opened  or not
                                    //if there is not a file called test.txt. then create it
  fout<<"now we have used fout the put some message to the test.txt";
  fout<<std::endl;
  fout<<"shut up baby!";
  fout.close();                     //after using ,we shoulf close the file
  std::ifstream fin;
  fin.open("test.txt");
  if(fin.fail())               //there are three ways to  makesure that the file has been opened or not
  {
    std::cout<<"the file test.txt was not found"<<std::endl;
    exit(1);
  }
  if(!fin)
  {
    std::cout<<"the file test.txt was not found "<<std::endl;
    exit(1);
  }
  if(!fin.is_open())
  {
    std::cout<<"the file test.txt was not found"<<std::endl;
    exit(1);
  }
  std::string line;
  while(std::getline(fin,line))
      std::cout<<line<<std::endl;
  fin.close();               //after using,we should close the file
  return 0;
}
