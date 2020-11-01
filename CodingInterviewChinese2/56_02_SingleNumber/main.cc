// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

//#include <assert.h>
//
//int singleNumber(const int* nums, int size) {
//  assert(nums != nullptr && size >= 4);
//
//  int bits[32] = {0};
//  for (int i = 0; i < size; ++i) {
//    int mask = 1;
//    bits[31] += nums[i] & mask;
//    for (int j = 1; j < 32; ++j) {
//      mask = mask << 1;
//      int bit = nums[i] & mask;
//      if (bit != 0) {
//        bits[31 - j] += 1;
//      }
//    }
//  }
//
//  int result = bits[0] %= 3;
//  for (int i = 1; i < 32; ++i) {
//    result = result << 1;
//    result |= bits[i] %= 3;
//  }
//
//  return result;
//}

#include <vector>

class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    int bits[32] = {0};
    for (std::vector<int>::size_type i = 0; i != nums.size(); ++i) {
      int num = nums[i];
      for (int j = 0; j < 32 && num != 0; ++j) {
        if ((num & 1) == 1) {
          ++bits[j];
        }
        num >>= 1;
      }
    }

    int result = bits[31]%3;
    for (int i = 30; i >= 0; --i) {
      result <<= 1;
      result += bits[i]%3;
    }

    return result;
  }
};

int main() {
  Solution sln;
  std::vector<int> t{3,4,3,3};
  int i = sln.singleNumber(t);
  return 0;
}
