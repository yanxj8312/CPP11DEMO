#include <thread>

void func()
{
    printf("hello world\n");
}

int main(int argc, char** argv)
{
    std::thread t(func);
    t.join();
    return 0;
}