// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m-1]。k[0]*k[1]*…*k[m-1]可能的最大乘积是多少？
// 例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到最大的乘积18。

#include <assert.h>
#include <math.h>
#include <stdint.h>

uint32_t integerBreakCore(uint32_t n) {
  if (n < 4) {
    return n; //not cut
  } else {
    uint32_t max = n - 1;
    for (uint32_t i = 1; i <= n/2; ++i) {
      uint32_t product = integerBreakCore(i)
          *integerBreakCore(n - i);
      if (product > max) {
        max = product;
      }
    }
    return max;
  }
}

uint32_t integerBreak(uint32_t n) {
  if (n < 2) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else if (n == 3) {
    return 2;
  } else {
    return integerBreakCore(n);
  }
}

uint32_t integerBreak1(uint32_t n) {
  if (n < 2) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else if (n == 3) {
    return 2;
  }
  uint32_t* products = new uint32_t[n + 1];
  products[0] = 0;
  products[1] = 1;
  products[2] = 2;
  products[3] = 3;
  for (uint32_t i = 4; i <= n; ++i) {
    uint32_t max = i - 1;
    for (uint32_t j = 1; j <= i/2; ++j) {
      uint32_t product = products[j]*products[i - j];
      if (product > max) {
        max = product;
      }
    }
    products[i] = max;
  }
  uint32_t max = products[n];
  delete[] products;
  return max;
}

uint32_t integerBreak2(uint32_t n) {
  if (n < 2) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else if (n == 3) {
    return 2;
  }

  uint32_t result = 1;
  while( n > 4 ) {
    result *= 3;
    n -= 3;
  }
  result *= n;
  return result;
}

int main() {
  assert(integerBreak(10) == 36);
  assert(integerBreak1(10) == 36);
  assert(integerBreak2(10) == 36);
  return 0;
}
