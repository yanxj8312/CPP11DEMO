#include <iostream>
#include <atomic>
//原子变量的使用方法

struct AtomicCounter {
    std::atomic<int> value;
    void increment()
    {
        ++value;
    }
    void decrement()
    {
        --value;
    }
    int get()
    {
        return value.load();
    }
};



int main(int argc,char** argv)
{

}