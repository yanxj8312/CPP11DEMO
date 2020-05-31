#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
// accumulate 求容器中相应范围内的和 
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
  v.push_back(1);
  v.push_back(10);
  v.push_back(100);

  std::cout<< accumulate(v.begin(),v.end(),5)<<std::endl;

  //fill 向容器中添加元素
  vector<int> v2;
  v2.resize(10);
  
  fill(v2.begin(),v2.end(),10);
  for_each(v2.begin(),v2.end(),MyPrint());
}


int main(int argc ,char** argv)
{

  test();
  return 0;
}