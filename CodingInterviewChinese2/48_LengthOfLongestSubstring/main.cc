// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。

#include <string.h>

int lengthOfLongestSubstring(const char* str) {
  int positions[26];
  memset(positions, -1, 26);
  int maxLen = 0;
  int curLen = 0;
  for (int i = 0; str[i] != '\0'; ++i) {
    if (positions[str[i] - 'a'] == -1) {
      ++curLen;
    } else {
      int d = i - positions[str[i] - 'a'];
      if (d <= curLen) {
        curLen = d;
      } else {
        ++curLen;
      }
    }
    positions[str[i] - 'a'] = i;

    if (curLen > maxLen) {
      maxLen = curLen;
    }
  }
  
  return maxLen;
}

int main() {
  return 0;
}
