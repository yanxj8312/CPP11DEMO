#include <iostream>

#include <algorithm>
#include <vector>
#include <list>

using namespace std;
//reverse 反转算法
struct MyPrint
{
  void operator()(int val)
  {
    std::cout<<val<<" ";
  }
};

void test()
{
  list<int> v;
  for(int i=0; i<9; i++)
  {
    v.push_back(i);
  }
  for_each(v.begin(),v.end(),MyPrint());
  reverse(v.begin(),v.end());
  for_each(v.begin(),v.end(),MyPrint());
}

int main(int argc, char** argv)
{
  test();
  return 0;
}