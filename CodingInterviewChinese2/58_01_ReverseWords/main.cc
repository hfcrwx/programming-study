// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student."，
// 则输出"student. a am I"。

#include <assert.h>

void reverse(char* begin, char* end) {
  assert(begin != nullptr && end != nullptr);

  while (begin < end) {
    char tmp = *begin;
    *begin = *end;
    *end = tmp;
  }
}

char* reverseWords(char* str) {
  assert(str != nullptr);
  
  char* begin = str;
  char* end = str;
  while (*end != '\0') {
    ++end;
  }
  --end;

  reverse(begin, end);

  end = str;
  while (*begin != '\0') {
    if (*begin == ' ') {
      ++begin;
      ++end;
    } else {
      if (*end != ' ' && *end != '\0') {
        ++end;
      } else {
        reverse(begin, --end);
        begin = ++end;
      }
    }
  }

  return str;
}

int main() {
  return 0;
}
