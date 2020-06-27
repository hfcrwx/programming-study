// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照递增排序的。例如输入图3
// .11中的链表1和链表2，则合并之后的升序链表如链表3所示。

// 1 3 5 7
// 2 4 6 8
// 1 2 3 4 5 6 7 8

#include <base/List.h>

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
  if (head1 == nullptr) {
    return head2;
  }
  if (head2 == nullptr) {
    return head1;
  }

  ListNode* newHead = nullptr;
  if (head1->value_ < head2->value_) {
    newHead = head1;
    newHead->next_ = mergeTwoLists(head1->next_, head2);
  } else {
    newHead = head2;
    newHead->next_ = mergeTwoLists(head1, head2->next_);
  }

  return newHead;
}

ListNode* mergeTwoLists2(ListNode* head1, ListNode* head2) {
  if (head1 == nullptr) {
    return nullptr;
  }
  if (head2 == nullptr) {
    return nullptr;
  }

  ListNode* newHead = nullptr;
  if (head1->value_ < head2->value_) {
    newHead = head1;
    head1 = head1->next_;
  } else {
    newHead = head2;
    head2 = head2->next_;
  }
  ListNode* pre = newHead;

  while (head1 != nullptr && head2 != nullptr) {
    if (head1->value_ < head2->value_) {
      pre->next_ = head1;
      head1 = head1->next_;
    } else {
      pre->next_ = head2;
      head2 = head2->next_;
    }
    pre = pre->next_;
  }

  if (head1 == nullptr) {
    pre->next_ = head2;
  }
  if (head2 == nullptr) {
    pre->next_ = head1;
  }

  return newHead;
}

int main() {
  return 0;
}
