// 面试题43：1~n整数中1出现的次数
// 题目：输入一个整数n，求1~n这n个整数的十进制表示中1出现的次数。例如，
// 输入12，1~12这些整数中包含1的数字有1，10，11和12，1一共出现了5次。

// 将 1 ~ n 的个位、十位、百位、...的 1 出现次数相加，即为 1 出现的总次数。
class Solution {
 public:
  int countDigitOne(int n) {
    int result = 0;

    int left = n;
    int right = 0;
    int digit = 0;
    int base = 1;
    while (left > 0) {
      digit = left%10;
      left /= 10;

      if (digit == 0) {
        result += left*base;
      } else if (digit == 1) {
        result += left*base + right + 1;
      } else {
        result += (left + 1)*base;
      }

      right += digit*base;
      base *= 10;
    }

    return result;
  }
};

class Solution1 {
 public:
  int countDigitOne(int n) {
    int result = 0;

    int digit = n % 10;
    int left = n / 10;
    int right = 0;
    int base = 1;
    while (left >= 0) {
      if (digit == 0) {
        result += left * base;
      } else if (digit == 1) {
        result += left * base + right + 1;
      } else {
        result += (left + 1) * base;
      }

      if (left == 0) {
        return result;
      }

      digit = left % 10;
      left /= 10;
      right += digit * base;
      base *= 10;
    }
  }
};

int main() {
  return 0;
}
