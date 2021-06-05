#include "LinkedList.hpp"

LinkedList::LinkedList(int head_) {
  head = new Node(head_);
}

LinkedList::LinkedList(Node *head_) {
  head = head_;
}

LinkedList::LinkedList(int * arr, size_t size) {
  head = new Node(arr[0]);
  Node *nhead = head;
  for (size_t i = 1; i < size; i++) {
      nhead->next = new Node(arr[i]);
      nhead = nhead->next;
  }
}

LinkedList::LinkedList(const LinkedList &oth) {
  new (this) LinkedList(oth.head);
}

LinkedList::~LinkedList() {
  delete head;
}

void LinkedList::add(int elem) {
  Node *nhead = head;
  while (nhead->next != nullptr) nhead = nhead->next;
  nhead->next = new Node(elem);
}


bool LinkedList::remove(int elem) {
  if (head != nullptr && head->val == elem) {
    Node * tmp = head;
    head = head->next;
    delete tmp;
    return 1;  
  }
  Node *nhead = head;
  Node *prev = nullptr;
  while (nhead != nullptr && nhead->val != elem) {
      prev = nhead;
      nhead = nhead->next;
  }
  if (!nhead) return 0;
  prev->next = nhead->next;
  delete nhead;
  return 1;
}

Node * LinkedList::returnHead() {
  return head;
}

void LinkedList::print() {
  Node *nhead = head;
  while (nhead != nullptr) {
      cout << nhead->val << " ";
      nhead = nhead->next;
  }
}

bool LinkedList::update(int prev, int newv) {
Node *nhead = head;
  while (nhead != nullptr) {
  if (nhead->val == prev) {
    nhead->val = newv;
    return 1;
  }
      nhead = nhead->next;
  }
return 0;
}
  
void LinkedList::println() {
  print();
  cout << endl;
}