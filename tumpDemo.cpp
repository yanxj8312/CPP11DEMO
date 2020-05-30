#include <iostream>
#include <string>
#include <tuple>

using namespace std;



int main(void)
{
  //构造一个tuple
  tuple<const char*,int>tp = make_tuple("hello",1);
  
  //构造一个tuple的左值引用
  //std::tuple<int&,string&,int&> tp1 = std::tie(1,"aa",2); //存疑


  return 0;
}
