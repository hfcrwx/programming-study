// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

// len为字符数组str的总容量，大于或等于字符串str的实际长度

// 时间复杂度O(n)
// 空间复杂度O(1)

void replaceSpaces(char* str, int len) {
  if (str==nullptr || len <= 0) {
    return;
  }

  int origLen = 0;
  int numSpaces = 0;
  for (int i = 0; str[i]!='\0'; ++i) {
    ++origLen;
    if (str[i]==' ') {
      ++numSpaces;
    }
  }

  int newLen = origLen + 2*numSpaces;
  if (newLen + 1 > len) {
    return;
  }
  for (int i = origLen, j = newLen; i >= 0 && j > i; --i) {
    if (str[i]==' ') {
      str[j--] = '0';
      str[j--] = '2';
      str[j--] = '%';
    } else {
      str[j--] = str[i];
    }
  }
}

int main() {
  char str[18] = "We are happy.";
  replaceSpaces(str, 18);
  return 0;
}
