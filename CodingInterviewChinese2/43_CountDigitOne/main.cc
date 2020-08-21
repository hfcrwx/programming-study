class Solution {
 public:
  int countDigitOne(int n) {
    int result = 0;

    int left = n;
    int right = 0;
    int currDigit = 0;
    int base = 1;
    while (left > 0) {
      currDigit = left%10;
      left /= 10;

      if (currDigit == 0) {
        result += left*base;
      } else if (currDigit == 1) {
        result += left*base + right + 1;
      } else {
        result += (left + 1)*base;
      }

      right += currDigit*base;
      base *= 10;
    }

    return result;
  }
};

int main() {
  return 0;
}
