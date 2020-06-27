// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。

// ->h->i->j->k->
// ...
// <-h  i->j->k->
// <-h  i  j->k->
// <-h<-i  j->k->
// ...

#include <base/List.h>

ListNode* reverseList(ListNode* head) {
  ListNode* reverseHead = nullptr;

  ListNode* pre = nullptr;
  ListNode* cur = head;
  while (cur != nullptr) {
    ListNode* next = cur->next_;
    if (next == nullptr) {
      reverseHead = cur;
    }
    cur->next_ = pre;

    pre = cur;
    cur = next;
  }

  return reverseHead;
}

int main() {
  return 0;
}
