// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。例如，序列{1,2,3,4,5}是某栈的压栈序列，
// 序列{4,5,3,2,1}是该压栈序列对应的一个弹出序列，
// 但{4,3,5,1,2}就不可能是该压栈序列的弹出序列。

#include <stack>

#include <assert.h>
#include <stddef.h>

bool validateStackSequences(const int* pushed,
                            size_t pushedSize,
                            const int* popped,
                            size_t poppedSize) {
  assert(pushed != nullptr && pushedSize != 0 && popped != nullptr
             && poppedSize != 0 && pushedSize == poppedSize);

  std::stack<int> stack;
  const int* push = pushed;
  const int* pop = popped;
  while (pop < popped + poppedSize) {
    while ((stack.empty() || stack.top() != *pop)
        && push < pushed + poppedSize) {
      stack.push(*push);
      ++push;
    }

    if (stack.top() != *pop) {
      return false;
    }

    stack.pop();
    ++pop;
  }

  return true;
}

int main() {
  return 0;
}
