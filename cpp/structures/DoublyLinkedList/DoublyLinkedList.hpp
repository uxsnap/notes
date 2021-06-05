#include "../DNode/DNode.hpp"

struct DoublyLinkedList {
  DoublyLinkedList();
  DoublyLinkedList(int);
  DoublyLinkedList(DNode *);
  DoublyLinkedList(int *, size_t size);
  DoublyLinkedList(const DoublyLinkedList &);
  ~DoublyLinkedList();

  void add_back(int);
  void add_front(int);

  bool update(int, int);

  DNode * find(int);

  bool insert_after(int, int);
  bool insert_before(int, int);

  bool remove(int);

  void print_front();
  void println_front();
  void print_back();
  void println_back();

private:
  DNode * head = nullptr;
  DNode * tail = nullptr;
};