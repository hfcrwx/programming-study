// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

#include <algorithm>
#include <vector>

class Solution {
 public:
  bool isStraight(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int numZero = 0;
    for (int i = 0; i < 5; ++i) {
      if (nums[i] == 0) {
        ++numZero;
      } else if (i > 0 && nums[i] == nums[i - 1]) {
        return false;
      }
    }

    return nums[4] - nums[numZero] <= 4;
  }
};

int main() {
  return 0;
}