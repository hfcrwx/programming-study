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

    int target = pow(10, base - 1) + (n - digitsCntPrev)/base - 1;
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
