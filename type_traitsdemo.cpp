#include <iostream>

//c++11之前定义常量的方法
template <typename T>
struct GetLeftSize
{
    static const int value = 1;
};

template <typename T>
struct GetLeftSize1
{
    enum {value = 1};
};

//c++11中定义编译期常量，不需要自己定义static const 或者enum类型，只需要从std::integral_constant派生
template<typename T>
struct GetLeftSize2:std::integral_constant<int,1>
{

};

template <class T, T v>
struct integral_constant
{
    static const T value = v;
    typedef T value_type;
    typedef integral_constant<T,v> type;
    operator value_type(){return value;}
};

template <class T>
struct is_integral;

typedef integral_constant<bool,true> true_type;
typedef integral_constant<bool,false> false_type;
//true_type 和 false_type 是编译期常量

class A{};
class B :public A{};
class C{};


int main(int argc,char** argv)
{
    //使用类型萃取判断模板类型是否为目标类型
    std::cout<<" is const "<<std::endl;
    std::cout<<"int: "<<std::is_const<int>::value<<std::endl;
    std::cout<<"const int: "<<std::is_const<const int>::value<<std::endl;

    //使用萃取判断两个类型是否相同
    std::cout<<"is same type "<<std::is_same<int ,unsigned int>::value<<std::endl;
    std::cout<<"is same type int ,int "<<std::is_same<int,int>::value<<std::endl;

    //使用萃取判断两个类型是否为继承关系
    //在is_base_of中 将第一个参数作为基类 第二个参数作为子类 使用的时候需要注意用法
    std::cout<<std::is_base_of<A,B>::value<<std::endl; //true
    std::cout<<std::is_base_of<B,A>::value<<std::endl; //false 
    std::cout<<std::is_base_of<C,B>::value<<std::endl; //false

    //使用萃取 判断前面的模板参数类型能否转换为后面的模板参数类型
    std::cout<<std::is_convertible<A*,B*>::value<<std::endl; //false
    std::cout<<std::is_convertible<B*,A*>::value<<std::endl; //true 
    std::cout<<std::is_convertible<C*,B*>::value<<std::endl; //false


    return 0;
}
