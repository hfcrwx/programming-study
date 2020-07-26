// 面试题57（二）：和为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如，输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。

#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findContinuousSequence(int target) {
    std::vector<std::vector<int>> result;
    int left = 1;
    int right = 2;
    while (left < right) {
      int sum = (right - left + 1)*(right + left)/2;
      if (sum == target) {
        std::vector<int> v;
        for (int i = left; i <= right; ++i) {
          v.push_back(i);
        }
        result.push_back(v);
        ++left;
      } else if (sum < target) {
        ++right;
      } else {
        ++left;
      }
    }

    return result;
  }
};

int main() {
  return 0;
}