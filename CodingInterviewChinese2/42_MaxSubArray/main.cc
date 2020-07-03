#include <assert.h>
#include <stddef.h>

int maxSubArray(const int* nums, size_t size) {
  assert(nums != nullptr && size != 0);

  int sum = nums[0];
  int m = sum;
  for (size_t i = 1; i < size; ++i) {
    if (sum < 0) {
      sum = nums[i];
    } else {
      sum += nums[i];
    }
    if (sum > m) {
      m = sum;
    }
  }

  return m;
}

int main() {
  return 0;
}
