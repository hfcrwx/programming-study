// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。

// ->h->i->j->k->
// ...
// <-h  i->j->k->
// <-h<-i  j->k->
// ...

#include <base/List.h>

ListNode* reverseList_iteratively(ListNode* head) {
//  assert(head != nullptr);
  ListNode* prev = nullptr;
  while (head != nullptr) {
    ListNode* next = head->next_;
    head->next_ = prev;

    prev = head;
    head = next;
  }

  return prev;
}

#include <assert.h>

ListNode* reverseList_recursively(ListNode* head) {
  assert(head != nullptr);

  if (head->next_ == nullptr) {
    return head;
  }

  ListNode* result = reverseList_recursively(head->next_);
  head->next_->next_ = head;
  head->next_ = nullptr;

  return result;
}

int main() {
  return 0;
}
