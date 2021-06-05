#include <new>
#include "../Node/Node.hpp"

struct LinkedList {
  LinkedList(int);
  LinkedList(Node *);
  LinkedList(int *, size_t size);
  LinkedList(const LinkedList &);
  ~LinkedList();
  
  void traverse(int (*)(int));
  
  int insertAfter(int, int);
  bool remove(int);
  void add(int);
  Node * returnHead();
  bool update(int, int);
  void print();
  void println();

private:
  Node * head;
};