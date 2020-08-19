// 面试题65：不用加减乘除做加法
// 题目：写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

int add(int a, int b) {
  while (b != 0) {
    int sum = a ^ b;
    int carry = (a & b) << 1;
    a = sum;
    b = carry;
  }
  return a;
}

int main() {
  int x = add(-1, -2);
  return 0;
}
