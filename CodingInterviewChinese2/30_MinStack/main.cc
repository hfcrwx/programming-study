// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
// 在该栈中，调用min、push及pop的时间复杂度都是O(1)。

#include <assert.h>
#include <stack>

template<typename T>
class MinStack {
 public:
  void push(const T& v);
  void pop();
  const T& min();
  const T& top() const ;
  T& top();

 private:
  std::stack<T> data_;
  std::stack<T> min_;
};

template<typename T>
void MinStack<T>::push(const T &v) {
  data_.push(v);
  if (min_.empty() || v < min_.top()) {
    min_.push(v);
  } else {
    min_.push(min_.top());
  }
}

template<typename T>
void MinStack<T>::pop() {
  assert(!data_.empty() && !min_.empty());
  data_.pop();
  min_.pop();
}

template<typename T>
const T& MinStack<T>::min() {
  assert(!data_.empty() && !min_.empty());
  return min_.top();
}

template<typename T>
const T& MinStack<T>::top() const {
  return data_.top();
}

template<typename T>
T& MinStack<T>::top() {
  return data_.top();
}

int main() {
  return 0;
}
