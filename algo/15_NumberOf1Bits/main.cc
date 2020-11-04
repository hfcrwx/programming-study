// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。
// 例如，把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

#include <assert.h>
#include <stdint.h>

uint32_t numberOf1Bits(uint32_t n) {
  uint32_t count = 0;
  while (n > 0) {
    if ((n & 1u) == 1) {
      ++count;
    }
    n >>= 1u;
  }
  return count;
}

uint32_t numberOf1Bits2(uint32_t n) {
  uint32_t count = 0;
  uint32_t flag = 1;
  while (flag > 0) {
    if ((n & flag) == 1) {
      ++count;
    }
    flag <<= 1u;
  }
  return count;
}

uint32_t numberOf1Bits3(uint32_t n) {
  uint32_t count = 0;
  while (n > 0) {
    ++count;
    n = n & (n - 1);
  }
  return count;
}

int main() {
  int x = 0x80000000 >> 1u;
  int y = 0x40000000;

  assert(numberOf1Bits(0x7FFFFFFF) == 31);
  assert(numberOf1Bits2(0x7FFFFFFF) == 31);
  assert(numberOf1Bits3(0x7FFFFFFF) == 31);
  return 0;
}
