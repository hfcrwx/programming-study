// 面试题10（一）：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

#include <inttypes.h>

uint64_t fabonacci(uint32_t i) {
  if (i == 0) {
    return 0;
  }
  if (i == 1) {
    return 1;
  }
  return fabonacci(i-1) + fabonacci(i-2);
}

uint64_t fabonacci2(uint32_t i) {
  uint64_t f0 = 0;
  uint64_t f1 = 1;
  if (i == 0) {
    return f0;
  }
  if (i == 1) {
    return f1;
  }

  uint64_t f2 = f0 + f1;
  for (int k = 3; k <= i; ++k) {
    f0 = f1;
    f1 = f2;
    f2 = f1 + f0;
  }

  return f2;
}

int main() {
  uint64_t res = fabonacci(10);
  uint64_t res2 = fabonacci2(100);
  return 0;
}
