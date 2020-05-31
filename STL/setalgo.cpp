#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
// 求两个set的差集 并集 和交集
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
  vector<int> v2;
  for(int i = 0; i< 10; i++)
  {
    v1.push_back(i);
  }

  for(int i = 5; i< 15; i++)
  {
    v2.push_back(i);
  }
  vector<int> v3;
  v3.resize(min(v1.size(),v2.size()));
  //求交集 ,返回的是交集的最后一个值的下一个位置
  vector<int>::iterator it = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

  for_each(v3.begin(),it,MyPrint()); std::cout<<std::endl;

}


int main(int argc ,char** argv)
{

  test();
  return 0;
}