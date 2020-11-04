// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复制一个复杂链表。在
// 复杂链表中，每个结点除了有一个m_pNext指针指向下一个结点，还有一个m_pSibling指针指向链表中的
// 任意结点或者nullptr。

#include <assert.h>

struct Node {
  int value_;
  Node* next_;
  Node* random_;
};

void copyNodes(Node* head);
void connectRandomNodes(Node* head);
Node* reconnectNodes(Node* head);

Node* copyRandomList(Node* head) {
  if (head == nullptr) {
    return nullptr;
  }

  copyNodes(head);
  connectRandomNodes(head);
  return reconnectNodes(head);
}

void copyNodes(Node* head) {
  assert(head != nullptr);

  Node* node = head;
  while (node != nullptr) {
    Node* cloned = new Node;
    cloned->value_ = node->value_;
    cloned->random_ = nullptr;
    cloned->next_ = node->next_;
    node->next_ = cloned;

    node = cloned->next_;
  }
}

void connectRandomNodes(Node* head) {
  assert(head != nullptr);

  Node* node = head;
  while (node != nullptr) {
    Node* cloned = node->next_;
    assert(cloned != nullptr);
    if (node->random_ != nullptr) {
      cloned->random_ = node->random_->next_;
    }

    node = cloned->next_;
  }
}

Node* reconnectNodes(Node* head) {
  assert(head != nullptr);

  Node* clonedHead = head->next_;

  Node* node = head;
  Node* cloned = head->next_;
  while (node != nullptr) {
    assert(cloned != nullptr);
    node->next_ = node->next_->next_;
    if (cloned->next_ != nullptr) {
      cloned->next_ = cloned->next_->next_;
    }

    node = node->next_;
    cloned = cloned->next_;
  }

  return clonedHead;
}

#include <map>

Node* copyRandomList2(Node* head) {
  Node* clonedHead = nullptr;

  Node* node = head;
  Node* cloned = nullptr;
  std::map<Node*, Node*> originToCloned;
  while (node != nullptr) {
    Node* p = new Node;
    p->value_ = node->value_;
    originToCloned[node] = p;
    if (cloned == nullptr) {
      clonedHead = p;
    } else {
      cloned->next_ = p;
    }
    cloned = p;

    node = node->next_;
  }

  node = head;
  cloned = clonedHead;
  while (cloned != nullptr) {
    cloned->random_ = originToCloned[node->random_];

    node = node->next_;
    cloned = cloned->next_;
  }

  return clonedHead;
}

int main() {
  return 0;
}
