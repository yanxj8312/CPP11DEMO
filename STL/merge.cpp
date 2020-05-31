#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
//merge 排序算法
using namespace std;


struct MyPrint
{
  void operator()(int val)
  {
    std::cout<<val<<" ";
  }
};

struct MyCompare
{
  bool operator()(int v1,int v2)
  {
    return v1<v2;
  }
};

void test()
{
  vector<int> v1;
  vector<int> v2;

  srand((unsigned int)time(NULL)); //时间种子

  for(int i =0 ;i < 10; i++)
  {
    v1.push_back(rand()%10);
  }
  for(int i =0 ;i < 10; i++)
  {
    v2.push_back(rand()%10);
  }
  vector<int> v3;
  v3.resize(v1.size() + v2.size()); //开辟空间

  sort(v1.begin(),v1.end(),MyCompare()); //v1v2必须式有序队列才能使用merge
  sort(v2.begin(),v2.end(),MyCompare());

  //std::iteraotr<vecotr<int>> it = v1.begin();
  merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin()); //合并v1v2 容器到v3中
  for_each(v3.begin(),v3.end(),MyPrint()); //匿名对象
}

int main(int argc, char** argv)
{
  test();
  return 0;
}