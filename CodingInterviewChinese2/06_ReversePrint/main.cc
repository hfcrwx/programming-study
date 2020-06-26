#include <base/List.h>
#include <stack>
#include <stdio.h>

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

void reversePrint_iteratively(const ListNode* head) {
  std::stack<const ListNode*> nodes;
  while (head != nullptr) {
    nodes.push(head);
    head = head->next_;
  }

  while (!nodes.empty()) {
    printf("%d ", nodes.top()->value_);
    nodes.pop();
  }
}

void reversePrint_recursively(const ListNode* head) {
  if (head != nullptr) {
    if (head->next_ != nullptr) {
      reversePrint_recursively(head->next_);
    }
    printf("%d ", head->value_);
  }
}

int main() {
  ListNode* node1 = createListNode(1);
  ListNode* node2 = createListNode(2);
  ListNode* node3 = createListNode(3);
  ListNode* node4 = createListNode(4);
  ListNode* node5 = createListNode(5);

  connectListNodes(node1, node2);
  connectListNodes(node2, node3);
  connectListNodes(node3, node4);
  connectListNodes(node4, node5);

  printList(node1);
  reversePrint_iteratively(node1);
  printf("\n");
  reversePrint_recursively(node1);

  destroyList(node1);

  return 0;
}
