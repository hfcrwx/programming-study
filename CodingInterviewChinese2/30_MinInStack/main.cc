#include <assert.h>
#include <stack>

template<typename T>
class stackWithMin {
 public:
  void push(const T& v);
  void pop();
  const T& min();
  const T& top();

 private:
  std::stack<T> data_;
  std::stack<T> min_;
};

template<typename T>
void stackWithMin<T>::push(const T &v) {
  data_.push(v);
  if (min_.empty() || v < min_.top()) {
    min_.push(v);
  } else {
    min_.push(min_.top());
  }
}

template<typename T>
void stackWithMin<T>::pop() {
  assert(!data_.empty() && !min_.empty());
  data_.pop();
  min_.pop();
}

template<typename T>
const T& stackWithMin<T>::min() {
  assert(!data_.empty() && !min_.empty());
  return min_.top();
}

template<typename T>
const T& stackWithMin<T>::top() {
  return data_.top();
}

int main() {
  return 0;
}