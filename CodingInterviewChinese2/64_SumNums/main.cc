// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
// 等关键字及条件判断语句（A?B:C）。

#include <assert.h>

class Solution {
 public:
  int sumNums(int n) {
    assert(n > 0);
    return n == 1 ? 1 : sumNums(n - 1) + n;
  }

  int sumNums2(int n) {
    assert(n >= 0);
    n && (n += sumNums(n - 1));
    return n;
  }
};

int main() {
  return 0;
}
