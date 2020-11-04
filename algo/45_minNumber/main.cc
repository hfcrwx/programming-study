// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
// 。例如，输入数组{3, 32, 321}，则打印出这3个数字能排成的最小数字321323。

#include <algorithm>
#include <string>
#include <vector>

#include <assert.h>

std::string minNumber(const int* nums, size_t size) {
  assert(nums != nullptr && size != 0);

  std::vector<std::string> strs;
  for (size_t i = 0; i < size; ++i) {
    strs.emplace_back(std::to_string(nums[i]));
  }
  std::sort(strs.begin(),
            strs.end(),
            [](const std::string& s1, const std::string& s2) {
              return s1 + s2 < s2 + s1;
            });
  std::string result = std::accumulate(strs.begin(), strs.end(), std::string());
  return result;
}

int main() {
  int numbers[] = {3, 323, 32123};
  std::string res = minNumber(numbers, sizeof(numbers)/sizeof(numbers[0]));
  return 0;
}
