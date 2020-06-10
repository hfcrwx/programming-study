// 面试题50（二）：字符流中第一个只出现一次的字符
// 题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从
// 字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'。当从该字
// 符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'。

#include <assert.h>
#include <limits>
#include <string.h>

class CharStat {
 public:
  CharStat() : index_(0) {
    memset(hash_, -1, sizeof(hash_));
  }
  void add(char c) {
    if (hash_[c] == -1) {
      hash_[c] = index_;
    } else if (hash_[c] >= 0) {
      hash_[c] = -2;
    }
    ++index_;
  }

  char firstAppearingOnce() {
    size_t minIndex = std::numeric_limits<int>::max();
    char c = '\0';
    for (size_t i = 0; i < sizeof(hash_)/sizeof(hash_[0]); ++i) {
      if (hash_[i] >= 0 && hash_[i] < minIndex) {
        minIndex = hash_[i];
        c = (char)i;
      }
    }
    return c;
  }

 private:
  int hash_[256];
  size_t index_;
};

int main() {
  CharStat c;

  c.add('g');
  assert(c.firstAppearingOnce()=='g');

  c.add('o');
  assert(c.firstAppearingOnce()=='g');

  c.add('o');
  assert(c.firstAppearingOnce()=='g');

  c.add('g');
  assert(c.firstAppearingOnce()=='\0');

  c.add('l');
  assert(c.firstAppearingOnce()=='l');

  c.add('e');
  assert(c.firstAppearingOnce()=='l');

  return 0;
}
