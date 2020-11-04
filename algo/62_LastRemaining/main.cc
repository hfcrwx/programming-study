// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。
// 求出这个圆圈里剩下的最后一个数字。

#include <assert.h>

class Solution {
 public:
  int lastRemaining(int n, int m) {
    assert(n > 0 && m > 0);
    int f = 0;
    for (int i = 2; i <= n; ++i) {
      f = (f + m)%i;
    }
    return f;
  }

  int lastRemaining2(int n, int m) {
    assert(n > 0 && m > 0);
    if (n == 1) {
      return 0;
    } else {
      return (lastRemaining(n - 1, m) + m)%n;
    }
  }
};

int main() {
  return 0;
}
