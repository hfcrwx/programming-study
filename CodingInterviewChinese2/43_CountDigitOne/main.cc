class Solution {
 public:
  int countDigitOne(int n) {
    int numOfOne = 0;

    int left = n;
    int right = 0;
    int currDigit = 0;
    int base = 1;
    while (left > 0) {
      currDigit = left%10;
      left = left/10;

      if (currDigit == 0) {
        numOfOne += left*base;
      } else if (currDigit == 1) {
        numOfOne += left*base + right + 1;
      } else {
        numOfOne += (left + 1)*base;
      }

      right = right + currDigit*base;
      base *= 10;
    }
    return numOfOne;
  }
};

int main() {
  return 0;
}
