#include "../TreeNode/TreeNode.hpp"

struct BinaryTree {
  BinaryTree(int data_) : root(new TreeNode(data_)) {}
  ~BinaryTree() {}
  void print();
  void insert(int);
  void remove(int);
  TreeNode * bfs(int);
  TreeNode * dfs(int);
private:
  void _print(TreeNode *);
  TreeNode *root;
};