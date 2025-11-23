/*
 * @lc app=leetcode id=510 lang=cpp
 *
 * [510] Inorder Successor in BST II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
 public:
  Node* inorderSuccessor(Node* node) {
    if (!node) return nullptr;
    if (node->right) {
      node = node->right;
      while (node->left) node = node->left;
      return node;
    } else if (node->parent) {
      while (node->parent && node->parent->left != node) node = node->parent;
      return node->parent;
    } else return nullptr;
  }
};
// @lc code=end
