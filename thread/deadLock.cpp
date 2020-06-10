#include <iostream>
#include <mutex>
#include <memory>

//死锁demo

struct Complex
{
    //std::mutex mutex;
    std::recursive_mutex mutex; //使用递归锁，可以避免死锁问题
    int i;
    Complex() : i(0) {}
    void mul(int x)
    {
        std::lock_guard<std::recursive_mutex> lock(mutex);
        i *= x;
    }
    void div(int x)
    {
        std::lock_guard<std::recursive_mutex> lock(mutex);
        i /= x;
    }

    void both(int x, int y)
    {
        std::lock_guard<std::recursive_mutex> lock(mutex);
        mul(x);
        div(y);
    }
};

int main(int argc, char **argv)
{
    Complex complex;
    complex.both(32,23);
    return 0;
}