#include <base/StringUtil.h>

#include <assert.h>
#include <string.h>

void leftRotate(char* str, size_t n) {
  assert(str != nullptr);
  assert(n < strlen(str));

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
