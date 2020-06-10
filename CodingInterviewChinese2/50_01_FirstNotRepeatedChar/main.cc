// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。

#include <assert.h>
#include <stddef.h>
#include <string.h>

char firstNotRepeated(const char* str) {
  assert(str != nullptr);

  char hash[256];
  bzero(hash, sizeof(hash));
  const char* p = str;
  while (*p != '\0') {
    ++hash[*p++];
  }

  p = str;
  while (*p != '\0') {
    if (hash[*p] == 1) {
      return *p;
    }
    ++p;
  }

  return '\0';
}

int main() {
  char x = firstNotRepeated("google");
  return 0;
}
