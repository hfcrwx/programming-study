#include <stddef.h>

int maxSum(const int* array, size_t len, int* errCode) {
  if (array == nullptr || len == 0) {
    *errCode = 1;
    return 0;
  }

  int maxSum = array[0];
  int currentSum = array[0];
  for (size_t i = 1; i < len; ++i) {
    if (currentSum < 0) {
      currentSum = array[i];
    } else {
      currentSum += array[i];
    }
    if (currentSum > maxSum) {
      maxSum = currentSum;
    }
  }

  return maxSum;
}

int main() {
  return 0;
}
