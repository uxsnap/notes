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
  size++;
  if (!tail) {
      tail = tmp;
      if (!head) head = tmp;
      return;
  }
  tail->next = tmp;
  tmp->prev = tail;
  tail = tmp;
}

void DoublyLinkedList::add_front(int val) {
  DNode *tmp = new DNode(val);
  size++;
  if (!head) {
      head = tmp;
      if (!tail) tail = tmp;
      return;
  }
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

void DoublyLinkedList::insert_into(int index, int val) {
  if (index == 0) return add_front(val);
  if (index == size) return add_back(val);
  DNode *tmp = new DNode(val);
  DNode *nhead = head;
  for (int i = 0; nhead != nullptr; nhead = nhead->next, i++) {
      if (i == index - 1) {
          DNode *nn = nhead->next; 
          nn->prev = tmp; 
          nhead->next = tmp;
          tmp->prev = nhead;
          tmp->next = nn;
          size++;
          return;
      }
  }
}
  
void DoublyLinkedList::remove_at(int index) {
  if ((index >= size) || (index < 0)) return;
  if (index == 0) {
      if (head == nullptr) return;
      DNode *tmp = head;
      head = tmp->next;
      delete tmp;
      size--;
      return;
  }
  if (index == size - 1) {
    if (tail == nullptr) return;
    DNode *tmp = tail;
    tail = tmp->prev;
    delete tmp;
    size--;
    return;
  }
  DNode *tmp = head->next;
  for (int i = 1; tmp != nullptr; tmp = tmp->next, i++) {
    if (i == index) {
      DNode *prev = tmp->prev;
      DNode *next = tmp->next;
      prev->next = next;
      next->prev = prev;
      delete tmp;
      size--;
      return;
    }
  }
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