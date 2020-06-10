// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。

#include <base/List.h>

#include <algorithm>
#include <stddef.h>

size_t length(const ListNode* head) {
  size_t len = 0;
  while (head != nullptr) {
    ++len;
    head = head->next_;
  }
  return len;
}

const ListNode* firstCommonNode(const ListNode* head1, const ListNode* head2) {
  if (head1 == nullptr || head2 == nullptr) {
    return nullptr;
  }

  size_t len1 = length(head1);
  size_t len2 = length(head2);

  if (len1 < len2) {
    std::swap(head1, head2);
    std::swap(len1, len2);
  }

  size_t diff = len1 - len2;
  const ListNode* p1 = head1;
  for (size_t i = 0; i < diff; ++i) {
    p1 = p1->next_;
  }

  const ListNode* p2 = head2;
  for (size_t i = 0; i < len2 - 1; ++i) {
    if (p1 == p2) {
      return p1;
    }
    p1 = p1->next_;
    p2 = p2->next_;
  }

  return nullptr;
}

int main() {
  return 0;
}
