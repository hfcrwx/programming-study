// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。

#include <base/StringUtil.h>

#include <assert.h>
#include <string.h>

void reverseLeftWords(char* str, size_t n) {
  assert(str != nullptr);
  assert(0 < n && n < strlen(str));

  char* begin1 = str;
  char* end1 = str + n - 1;
  char* begin2 = str + n;
  char* end2 = str + strlen(str) - 1;
  reverse(begin1, end1);
  reverse(begin2, end2);
  reverse(begin1, end2);
}

int main() {
  return 0;
}
