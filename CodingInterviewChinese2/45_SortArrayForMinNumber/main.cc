// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。

#include <algorithm>
#include <string>
#include <vector>

std::string minNumber(const int* numbers, size_t len) {
  if (numbers == nullptr || len == 0) {
    return std::string();
  }
  std::vector<std::string> strs;
  for (size_t i = 0; i < len; ++i) {
    strs.push_back(std::to_string(numbers[i]));
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
