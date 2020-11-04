// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出'b'。

#include <assert.h>
#include <string.h>

char firstUniqChar(const char* str) {
  assert(str != nullptr);

  int hash[256];
  bzero(hash, sizeof(hash));
//  const char* p = str;
//  while (*p != '\0') {
//    ++hash[*(const unsigned char*)(p++)];
//  }

//  p = str;
//  while (*p != '\0') {
//    if (hash[*(const unsigned char*)p] == 1) {
//      return *p;
//    }
//    ++p;
//  }

  for (const char* p = str; *p != '\0'; ++p) {
    ++hash[*(const unsigned char*) p];
  }

  for (const char* p = str; *p != '\0'; ++p) {
    if (hash[*(const unsigned char*) p] == 1) {
      return *p;
    }
  }

  return '\0';
}

int main() {
  char x = firstUniqChar("google");
  char a[3];
  a[0] = -1;
  a[1] = -2;
  a[2] = 0;
  char y = firstUniqChar(a);
  return 0;
}
