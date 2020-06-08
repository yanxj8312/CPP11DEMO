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


//循环引用场景

struct A;
struct B;

struct A
{
  std::shared_ptr<B> bptr;
  ~A(){cout<<"A is deleted"<<endl;}
};

struct B
{
  std::shared_ptr<A> aptr;
  ~B(){cout<<"B is deleted"<<endl;}
};

//该测试下a和b都不会被删除，存在内存泄漏，循环引用导致ap和bp的引用计数为2，离开作用域之后引用计数为1，并不会为0
void TestPtr()
{
  {
    std::shared_ptr<A> ap(new A);
    std::shared_ptr<B> bp(new B);
    ap->bptr = bp;
    bp->aptr = ap;
  }
}


int main(int arg,char** argv)
{
  test();
  return 0;
}