// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意第n位对应的数字。

#include <math.h>

class Solution {
 public:
  int findNthDigit(int n) {
    long digitsCnt = 0;
    long digitsCntPrev = 0;
    int base = 0;
    for (; digitsCnt < n; base++) {
      digitsCntPrev = digitsCnt;
      digitsCnt = digitsCnt + 9*pow(10, base)*(base + 1);
    }

    int target = pow(10, base - 1) - 1 + (n - digitsCntPrev)/base;
    int left = (n - digitsCntPrev)%base;

    if (left == 0) {
      return target%10;
    } else {
      target++;
      return target/(int) pow(10, base - left)%10;
    }
  }
};

int main() {
  return 0;
}
