#include <new>
#include "../Node/Node.hpp"

struct LinkedList {
  LinkedList(int);
  LinkedList(Node *);
  LinkedList(const LinkedList &);
  ~LinkedList();
  
  void traverse(int (*)(int));
  
  int insertAfter(int, int);
  bool remove(int);
  void add(int);
  Node * returnHead();

private:
  Node * head;
};