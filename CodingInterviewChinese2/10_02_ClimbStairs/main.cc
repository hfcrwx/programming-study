// 面试题10（二）：青蛙跳台阶问题
// 题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。
// 求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

#include <assert.h>
#include <inttypes.h>

uint32_t climbStairs(uint32_t n) {
  assert(n != 0);

  uint32_t f1 = 1;
  if (n == 1) {
    return f1;
  }

  uint32_t f2 = 2;
  if (n == 2) {
    return f2;
  }

  uint32_t f3 = f2 + f1;
  for (int i = 4; i <= n; ++i) {
    f1 = f2;
    f2 = f3;
    f3 = f2 + f1;
  }

  return f3;
}

int main() {
  return 0;
}
