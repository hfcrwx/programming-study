// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
// 如果有多对数字的和等于s，输出任意一对即可。

#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result;
    std::vector<int>::size_type left = 0;
    std::vector<int>::size_type right = nums.size() - 1;
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum == target) {
        result.push_back(nums[left]);
        result.push_back(nums[right]);
        return result;
      } else if (sum < target) {
        ++left;
      } else {
        --right;
      }
    }

    return result;
  }
};

int main() {
  return 0;
}
