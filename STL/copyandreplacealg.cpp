#include <iostream>

#include <algorithm>
#include <vector>
#include "time.h"

using namespace std;

//copy swap
struct MyPrint
{
  void operator()(int val)
  {
    std::cout<<val<<" ";
  }
};

void test()
{
  vector<int> v1;

  srand((unsigned int)time(NULL)); //时间种子

  for(int i =0 ;i < 10; i++)
  {
    v1.push_back(rand()%10);
  }
  vector<int> v2;
  v2.resize(v1.size());

  copy(v1.begin(),v1.end(),v2.begin());
  for_each(v1.begin(),v1.end(),MyPrint());
  std::cout<<std::endl;
  for_each(v2.begin(),v2.end(),MyPrint());
  std::cout<<std::endl;

  vector<int>v3;
    for(int i =0 ;i < 10; i++)
  {
    v3.push_back(rand()%10);
  }
  for_each(v3.begin(),v3.end(),MyPrint());
  std::cout<<std::endl;

  swap(v3,v2);
  for_each(v2.begin(),v2.end(),MyPrint());
  std::cout<<std::endl;

  for_each(v3.begin(),v3.end(),MyPrint());
  std::cout<<std::endl;
}



int main(int argc, char** argv)
{
  test();

  return 0;
}
