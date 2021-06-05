struct DNode {
  DNode() {}
  DNode(int val_) : val(val_) {}
  int val;
  DNode * next = nullptr;
  DNode * prev = nullptr;
};
