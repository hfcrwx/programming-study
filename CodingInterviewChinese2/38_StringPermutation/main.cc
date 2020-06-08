#include <stdio.h>

void permutationCore(char* str, char* start) {
  if (*start=='\0') {
    printf("%s\n", str);
    return;
  }

  for (char* c=start; *c!='\0'; ++c) {
    char tmp = *c;
    *c = *start;
    *start = tmp;

    permutationCore(str, start+1);

    tmp = *c;
    *c = *start;
    *start = tmp;
  }
}

void permutation(char* str) {
  if (str==nullptr) {
    return;
  }
  permutationCore(str, str);
}

int main() {
  return 0;
}
