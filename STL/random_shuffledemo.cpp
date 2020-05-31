#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;
//random_shuffle 洗牌算法
struct MyPrint
{
  void operator()(int val)
  {
    std::cout<<val<<" ";
  }
};



void test()
{
  vector<int> v;
  for(int i=0; i<9; i++)
  {
    v.push_back(i);
  }

  for_each(v.begin(),v.end(),MyPrint());
  std::cout<<std::endl;
  random_shuffle(v.begin(),v.end());

  for_each(v.begin(),v.end(),MyPrint());
}

int main(int arg, char** argv)
{
  test();
  return 0;
}

