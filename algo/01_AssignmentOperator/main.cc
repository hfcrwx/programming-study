// 面试题1：赋值运算符函数
// 题目：如下为类型MyString的声明，请为该类型添加赋值运算符函数。

#include <string.h>

class MyString {
 public:
  MyString(const char* str = nullptr);
  ~MyString();
  MyString(const MyString&);
  MyString& operator=(const MyString&);

 private:
  char* data_;
};

MyString::MyString(const char* str) {
  if (str==nullptr) {
    data_ = new char[1];
    *data_ = '\0';
  } else {
    data_ = new char[strlen(str) + 1];
    strcpy(data_, str);
  }
}

MyString::~MyString() {
  delete[] data_;
}

MyString::MyString(const MyString& str) {
  data_ = new char[strlen(str.data_) + 1];
  strcpy(data_, str.data_);
}

MyString& MyString::operator=(const MyString& str) {
  if (this!=&str) {
    delete[] data_;
    data_ = new char[strlen(str.data_) + 1];
    strcpy(data_, str.data_);
  }
  return *this;
}

int main() {
  return 0;
}
