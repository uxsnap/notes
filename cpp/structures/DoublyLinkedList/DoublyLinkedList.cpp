#include <iostream>
#include "DoublyLinkedList.hpp"
using namespace std;

DoublyLinkedList::DoublyLinkedList() {}

DoublyLinkedList::DoublyLinkedList(int val) {
    DNode *nnode = new DNode(val);
    head = nnode;
    tail = nnode;
    head->next = tail;
    tail->prev = head;
}

DoublyLinkedList::DoublyLinkedList(DNode * node) : head(node), tail(node) {
    head->next = tail;
    tail->prev = head;
}

DoublyLinkedList::DoublyLinkedList(int * arr, size_t size) {
  head = new DNode(arr[0]);
  DNode * nhead = head;
  for (size_t i = 1; i < size; i++) {
     nhead->next = new DNode(arr[i]);
     DNode *tmp = nhead;
     nhead = nhead->next;
     nhead->prev = tmp;
  }
  tail = nhead;
}

DoublyLinkedList::~DoublyLinkedList() {
  if (head == nullptr) return;
  if (head && head->next != nullptr) {
      DNode* nhead = head->next;
      while (nhead != nullptr) {
          DNode * tmp = nhead;
          nhead = nhead->next;
          delete tmp;
      }
  }
  delete head;
}
  
void DoublyLinkedList::add_back(int val) {
  DNode *tmp = new DNode(val);
  tail->next = tmp;
  tmp->prev = tail;
  tail = tmp;
}

void DoublyLinkedList::add_front(int val) {
  DNode *tmp = new DNode(val);
  head->prev = tmp;
  tmp->next = head;
  head = tmp;
}
  
bool DoublyLinkedList::update(int elem, int val) {
  DNode * nhead = find(elem);
  
  if (!nhead) return 0;
  
  nhead->val = val;
  return 1;
}
  
DNode * DoublyLinkedList::find(int elem) {
  DNode * nhead = head;
  while (nhead != nullptr && nhead->val != elem) {
     nhead = nhead->next;
  }
  
  return nhead;
}

bool DoublyLinkedList::insert_after(int elem, int val) {
  DNode * nhead = find(elem);
  if (!nhead) return 0;
  DNode * tmp = new DNode(val);
  tmp->next = nhead->next;
  tmp->prev = nhead;
  if (tmp->next != nullptr) {
      tmp->next->prev = tmp;
  } else { delete tmp; add_back(val); }
  nhead->next = tmp; 
  return 1;
}

bool DoublyLinkedList::insert_before(int elem, int val) {
  DNode * nhead = find(elem);
  if (!nhead) return 0;
  DNode * tmp = new DNode(val);
  tmp->prev = nhead->prev;
  tmp->next = nhead;
  if (tmp->prev != nullptr) {
      tmp->prev->next = tmp;
  } else { delete tmp; add_front(val); }
  nhead->prev = tmp;
  return 1;
}
  
bool DoublyLinkedList::remove(int val) {
  if (head->val == val) {
    DNode * tmp = head;
    head->next->prev = nullptr;
    head = head->next;
    delete tmp;
    return 1;
  }  
  
  if (tail->val == val) {
    DNode * tmp = tail;
    tail->prev->next = nullptr;
    tail = tail->prev;
    delete tmp;
    return 1;
  }
  
  DNode *prev = nullptr;
  DNode *nhead = head;
  while (nhead != nullptr && nhead->val != val) {
     prev = nhead;
     nhead = nhead->next;
  }
  
  if (!nhead) return 0;
  
  DNode * tmp = nhead;
  nhead = nhead->next;
  prev->next = nhead;
  nhead->prev = prev;
  delete tmp;
  return 1;
}
  
void DoublyLinkedList::print_front() {
  DNode *nhead = head;
  while (nhead != nullptr) {
      cout << nhead->val << " ";
      nhead = nhead->next;
  }
}

void DoublyLinkedList::println_front() {
  print_front();
  cout << endl;
}

void DoublyLinkedList::print_back() {
  DNode *ntail = tail;
  while (ntail != nullptr) {
    cout << ntail->val << " ";
    ntail = ntail->prev;
  }
}

void DoublyLinkedList::println_back() {
  print_back();
  cout << endl;
}