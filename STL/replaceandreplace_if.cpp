#include <iostream>

#include <algorithm>
#include <vector>
#include "time.h"

using namespace std;

//replace replace_if
struct MyPrint
{
  void operator()(int val)
  {
    std::cout<<val<<" ";
  }
};

struct MyCompare 
{
  bool operator()(int val)
  {
    return val > 5; 
  }
};

void test()
{
  vector<int> v1;

  //srand((unsigned int)time(NULL)); //时间种子

  for(int i =0 ;i < 10; i++)
  {
    v1.push_back(i);
  }

  for_each(v1.begin(),v1.end(),MyPrint()); std::cout<<std::endl;

  replace(v1.begin(),v1.end(),5,100);

  for_each(v1.begin(),v1.end(),MyPrint()); std::cout<<std::endl;

  replace_if(v1.begin(),v1.end(),MyCompare(),30);
  for_each(v1.begin(),v1.end(),MyPrint()); std::cout<<std::endl;

}



int main(int argc, char** argv)
{
  test();

  return 0;
}