// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent次方。
// 不得使用库函数，同时不需要考虑大数问题。

#include <limits>
#include <stdint.h>

double myPow(double x, int n) {
  bool sign = false;
  unsigned int exp = n;
  if (n < 0) {
    exp = -n;
    sign = true;
  }
  double result = 1.0;
  while (exp > 0) {
    if ((exp & 1) == 1) {
      result *= x;
    }
    x *= x;
    exp >>= 1;
  }

  return sign ? 1/result : result;
}

uint32_t errcode = 0;

bool equal(double v1, double v2) {
  return v1 - v2 < std::numeric_limits<double>::epsilon()
      || v1 - v2 > -std::numeric_limits<double>::epsilon();
}

double powerWithUnsignedExp(double base, uint32_t exp) {
  double res = 1;
  for (uint32_t i = 0; i < exp; ++i) {
    res *= res;
  }
  return res;
}

double powerWithUnsignedExp_Recusive(double base, uint32_t exp) {
  if (exp == 0) {
    return 1;
  } else if (exp == 1) {
    return base;
  } else {
    double res = powerWithUnsignedExp_Recusive(base, exp >> 1);
    res *= res;
    if ((exp & 0x1) == 1) {
      res *= base;
    }
    return res;
  }
}

double power(double base, int32_t exp) {
  if (equal(base, 0) && exp < 0) {
    errcode = 1;
    return 0;
  }
  return exp >= 0 ? powerWithUnsignedExp(base, exp) : 1
      /powerWithUnsignedExp(base, -exp);
}

#include <math.h>

int main() {
  double x = pow(0, 0);
  return 0;
}
