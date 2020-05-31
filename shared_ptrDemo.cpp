#include <iostream>
#include <string>
#include <memory>

using namespace std;

void test()
{
  //std::shared_ptr<int> ptr1 = new int(1); //错误原始指针不能直接赋值给智能指针，只能通过make_shared来构造一个智能指针赋值
  std::shared_ptr<int> p(new int(1));
  std::shared_ptr<int> p2 = p;
  std::shared_ptr<int> ptr;
  ptr.reset(new int(1));
  if(ptr){
    cout<<"ptr is not null"<<endl;
  }

  //获取原始指针
  int *p1 = p.get();
  cout<<*p1<<endl;
}


int main(int arg,char** argv)
{
  test();
  return 0;
}