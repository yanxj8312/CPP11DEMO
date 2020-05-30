#include <iostream>
#include <string>

using namespace std;

//decltype 的不同调用方法

//类型访问
class foo
{
public:
  static const int Number = 0;
  int x;
};

int decltypeClass()
{
  int n = 0; 
  volatile const int &x = n;

  decltype(n) a = n; //int
  decltype(x) b = n; //const volatile int &
  decltype(foo::Number) c = 0; //const int 
  foo f;
  decltype(f.x) d = 0; // int 类访问表达式
}


//函数调用

int& func_int_r(void);  //左值
int&& func_int_rr(void); //x值 右值引用本身是一个xvalue
int func_int(void); //纯右值

const int& func_cint_r(void);// 左值
const int&& func_cint_rr(void);//x值
const int func_cint(void);  //纯右值
const foo func_cfoo(void) ;//纯右值

int decltypeFunc(void)
{
  int x = 0;
  decltype(func_int_r()) a1=x; //a1 -> int &
  decltype(func_int_rr()) b1=0; //b1 -> int&&
  decltype(func_int()) c1 = 0; //c1->int 

  decltype(func_cint_r()) a2=x; //a2 ->const int &;
  decltype(func_cint_rr()) b2=0; //b2 -> const int &&;
  decltype(func_cint()) c2 = 0; //c2 -> int
  decltype(func_cfoo()) ff = foo(); //ff ->  const foo;

}


int main(int argc, char** argv)
{
  int x = 0;

  decltype(x) y=1;  //y为int类型

  decltype(x+y) z=0; //z 为int类型

  const int& i = y; 
  decltype(i) j=y;  //j 为 const int & 

  const decltype(z)*p = &z; //*p为const int p为const int*
  decltype(z)* pi = &z; //*pi -> int pi -> int*
  decltype(pi)*pp = &pi;  //*pp -> int *, pp -> int**
  

  return 0;
}