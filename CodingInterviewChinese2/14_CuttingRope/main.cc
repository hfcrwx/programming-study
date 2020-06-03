// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m-1]。k[0]*k[1]*…*k[m-1]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

#include <assert.h>
#include <math.h>
#include <stdint.h>

uint32_t maxProductAfterCuttingCore_recursively(uint32_t len) {
  if (len < 4) {
    return len;
  } else {
    uint32_t max = len - 1;
    for (uint32_t i = 1; i <= len/2; ++i) {
      uint32_t product = maxProductAfterCuttingCore_recursively(i) * maxProductAfterCuttingCore_recursively(len-i);
      if (product > max) {
        max = product;
      }
    }
    return max;
  }
}

uint32_t maxProductAfterCutting_recursively(uint32_t len) {
  if (len <2) {
    return 0;
  } else if (len == 2) {
    return 1;
  } else if (len == 3) {
    return 2;
  } else {
    return maxProductAfterCuttingCore_recursively(len);
  }
}

uint32_t maxProductAfterCutting1(uint32_t len) {
  if (len <2) {
    return 0;
  } else if (len == 2) {
    return 1;
  } else if (len == 3) {
    return 2;
  }
  uint32_t* products = new uint32_t[len+1];
  products[0] = 0;
  products[1] = 1;
  products[2] = 2;
  products[3] = 3;
  for (uint32_t i = 4; i <= len; ++i) {
    uint32_t max = len - 1;
    for (uint32_t j = 1; j <= i/2; ++j) {
      uint32_t product = maxProductAfterCuttingCore_recursively(j) * maxProductAfterCuttingCore_recursively(i-j);
      if (product > max) {
        max = product;
      }
    }
    products[i] = max;
  }
  uint32_t max = products[len];
  delete [] products;
  return max;
}

uint32_t maxProductAfterCutting2(uint32_t len) {
  if (len <2) {
    return 0;
  } else if (len == 2) {
    return 1;
  } else if (len == 3) {
    return 2;
  }

  uint32_t timeOf3 = len/3;
  if (len%3 == 1) {
    timeOf3 -= 1;
  }
  uint32_t timeOf2 = (len - 3 * timeOf3) / 2;
  return static_cast<uint32_t>(pow(3, timeOf3)* pow(2, timeOf2));
}

int main() {
  assert(maxProductAfterCutting_recursively(10) == 36);
  assert(maxProductAfterCutting1(10) == 36);
  assert(maxProductAfterCutting2(10) == 36);
  return 0;
}
