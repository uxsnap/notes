#include "LinkedList.hpp"

LinkedList::LinkedList(int head_) {
  head = new Node(head_);
}

LinkedList::LinkedList(Node *head_) {
  head = head_;
}

LinkedList::LinkedList(const LinkedList &oth) {
  new (this) LinkedList(oth.head);
}

LinkedList::~LinkedList() {
  delete head;
}

void LinkedList::add(int data) {
  Node * nhead = head;
  while ((nhead = nhead->next) != nullptr);
  nhead = new Node(data);
}


bool LinkedList::remove(int data) {
  if (head->data == data) {
    head = head->next;
    return 1;
  }

  Node * nhead = head;
  while (nhead != nullptr) {
    if (nhead->next->data == data) {
      nhead->next = nhead->next->next;
      return 1;
    }
  }

  return 0;
}

Node * LinkedList::returnHead() {
  return head;
}

void LinkedList::traverse(int f(int)) {
  Node * nhead = head;
  while (nhead->next != nullptr) {
    nhead->data = f(nhead->data);
    nhead = nhead->next;
  }
}