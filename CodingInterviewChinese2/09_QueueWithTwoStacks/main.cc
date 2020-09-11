// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail和deleteHead，
// 分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#include <stack>

template<typename T>
class Queue {
 public:
  Queue();
  ~Queue();
  void appendTail(const T&); //push
  T deleteHead(); //pop, front

 private:
  std::stack<T> stack1_;
  std::stack<T> stack2_;
};

template<typename T>
Queue<T>::Queue() {

}

template<typename T>
Queue<T>::~Queue() {

}

template<typename T>
void Queue<T>::appendTail(const T& v) {
  stack1_.push(v);
}

template<typename T>
T Queue<T>::deleteHead() {
  if (stack2_.empty()) {
    while (!stack1_.empty()) {
      const T& v = stack1_.top();
      stack2_.push(v);
      stack1_.pop();
    }
  }

  if (!stack2_.empty()) {
    T v=  stack2_.top();
    stack2_.pop();
    return v;
  } else {
    throw std::exception();
  }
}

int main() {
  return 0;
}
