#include <iostream>
#include <memory>
#include <string>
 
 //使用unique_ptr的链表
 template <typename T>
 struct Node
 {
   T data;
   std::unique_ptr<Node<T>> next;
 };
  template<typename T>
 class Link
 {
public:
  void push_front(const T& val)
  {
    auto node = std::make_unique<Node<T>>();
    node->data = val;
    node->next = std::move(_head.next);
    _head.next = std::move(node);
  }

  void print()
  {
    Node<T>*node = _head.next.get();
    while(node)
    {
      std::cout<<node->data<<" ";
      node = node->next.get();
    }
  }

  private:
  Node<T> _head;
 };



//unique_ptr 独有指针，不能两个指针之间共享
void test()
{
  std::unique_ptr<std::string> arr = std::make_unique<std::string>("hello world");
  std::unique_ptr<std::string> ptr = std::move(arr);
  std::cout<<*ptr<<std::endl;
  //std::cout<<*arr<<std::endl; move之后就不存在资源，无法输出资源
}

int main(int argc, char** argv)
{
  //test();
  Link<int> lk;
  for(int i = 0; i < 5; i++)
  {
    lk.push_front(i);
  }
  lk.print();

  return 0;
}