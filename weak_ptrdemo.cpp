#include <iostream>
#include <memory>
using namespace std;

//通过lock方法来获取所监视的sharedptr
std::weak_ptr<int> gw;

void f()
{
    if (gw.expired()) //所监视的shard_ptr是否释放
    {
        std::cout << "gw is expired\n";
    }
    else
    {
        auto spt = gw.lock();
        std::cout << *spt << endl;
    }
}

int main(int argc, char **argv)
{
    shared_ptr<int> sp(new int(10));
    weak_ptr<int> wp(sp);

    //通过use_count方法来获得所观测的资源的引用计数
    cout << wp.use_count() << endl;

    //通过expired方法来判断所观测的资源是否已经被释放
    if (wp.expired())
        std::cout << "weak_ptr 无效，所监视的资源已经被释放" << endl;
    else
        std::cout << "weak_ptr 有效" << endl;

    {
        auto sp = std::make_shared<int>(42);
        gw = sp;
        f();
    }
    f();

    return 0;
}