#include <iostream>
#include <algorithm>
#include <vector>
//适配器模式 将接口转换为客户希望的接口
using namespace std;

struct MyPrint
{
  void operator()(int val1,int val2)
  {
    cout<<val1+val2<<" ";
  }
};

//定义接口，我要适配的样子
class Target{
  public:
  virtual void operator()(int v) =0;
};

class Adapter : public Target
{
public:
  Adapter(int val)
  {
    this->para = val;
  }
  virtual void operator()(int v)
  {
    print(v, para);
  }
private:
  MyPrint print;
  int para;
};

Adapter myBind(int val)
{
  return Adapter(val);
}


void test()
{
  vector<int> v1;

  for(int i = 0; i < 10; i++)
  {
    v1.push_back(i);
  }

  for_each(v1.begin(),v1.end(),myBind(10));
}

int main(int argc,char** argv)
{
  test();

  return 0;
}