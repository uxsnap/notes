#include "BinaryTree.hpp"

#include <iostream>

using namespace std;

void BinaryTree::print() {
  if (!root) return;
  _print(root);
}

void BinaryTree::_print(TreeNode * node) {
  if (!node) return;
  cout << node->data;
  _print(node->left); 
  _print(node->right); 
} 

// void BinaryTree::insert(int val) {
//   TreeNode *traverseNode = val > data ? left : right;
//   TreeNode *tmp = new TreeNode(val);
//   while (traverseNode) {
//     if (val > traverseNode->data) traverseNode = traverseNode->left;
//     else traverseNode = traverseNode->right;
//   }
// }