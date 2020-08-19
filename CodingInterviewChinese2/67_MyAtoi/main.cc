// 面试题67：把字符串转换成整数
// 题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。
// 当然，不能使用atoi或者其他类似的库函数。

#include <assert.h>
#include <ctype.h>

#define INT_MAX 0x7FFFFFFF
#define INT_MIN 0x80000000

int myAtoi(const char* str) {
  assert(str != nullptr);

  for (; isspace(*str); ++str);
  bool neg;
  if (*str == '-') {
    neg = true;
    ++str;
  } else if (*str == '+') {
    neg = false;
    ++str;
  } else {
    neg = false;
  }

  int ret = 0;
  for (; isdigit(*str); ++str) {
    int digit = *str - '0';
    if (!neg) {
      if (ret > (INT_MAX - digit)/10) {
        return INT_MAX;
      }
      ret = ret*10 + digit;
    } else {
      if (ret < (INT_MIN + digit)/10) {
        return INT_MIN;
      }
      ret = ret*10 - digit;
    }
  }

  return ret;
}

int main() {
  return 0;
}
