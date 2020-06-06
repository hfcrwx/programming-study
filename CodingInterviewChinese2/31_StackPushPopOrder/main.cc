// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

#include <stack>
#include <stddef.h>

bool isPopOrder(const int* pushOrder, const int* popOrder, size_t len) {
  if (pushOrder==nullptr || popOrder==nullptr || len==0) {
    return false;
  }

  std::stack<int> stack;
  const int* push = pushOrder;
  const int* pop = popOrder;
  while (pop < popOrder + len) {
    while ((stack.empty() || stack.top()!=*pop) && push < pushOrder + len) {
      stack.push(*push);
      ++push;
    }

    if (stack.top()!=*pop) {
      return false;
    }
    stack.pop();
    ++pop;
  }
  return false;
}

int main() {
  return 0;
}
