#include <iostream>
#include <memory>

using namespace std;

//支持普通指针
template <class T, class ... Args>inline 
typename enable_if<!is_array<T>::value,unique_ptr<T>>::type
make_unique(Args&&... args)
{
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

//支持动态数组
template<class T> inline
typename enable_if<is_array<T>::value && extent<T>::value==0, unique_ptr<T>>::type
make_unique(size_t size)
{
    typedef typename remove_extent<T>::type U;
    return unique_ptr<T>(new U[size]());
}

//过滤掉定长数组的情况
template<class T,class... Args>
typename enable_if<extent<T>::value!=0,void>::type make_unique(Args&&...)=delete;

//自定义unique_ptr 删除器
#include <functional>

struct MyDeleter
{
    void operator()(int*p)
    {
        cout<<"delete"<<endl;
        delete p;
    }
};

int main() {
    std::unique_ptr<int, MyDeleter> p(new int(1));
    return 0;
}