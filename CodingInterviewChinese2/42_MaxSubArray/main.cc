// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子
// 数组的和的最大值。要求时间复杂度为O(n)。

#include <assert.h>
#include <stddef.h>

//i=0: s[0]=n[0]
//i>0: s[i-1]>0:  s[i]=s[i-1]+n[i]
//     s[i-1]<=0: s[i]=n[i]
//x=max(s[i])

int maxSubArray(const int* nums, size_t size) {
  assert(nums != nullptr && size != 0);

  int sum = nums[0];
  int maxSum = sum;
  for (size_t i = 1; i < size; ++i) {
    if (sum <= 0) {
      sum = nums[i];
    } else {
      sum += nums[i];
    }
    if (sum > maxSum) {
      maxSum = sum;
    }
  }
  return maxSum;
}

int main() {
  return 0;
}
