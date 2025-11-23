/*
 * @lc app=leetcode id=426 lang=cpp
 *
 * [426] Convert Binary Search Tree to Sorted Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
 public:
  // Node* treeToDoublyList(Node* root) {
  //   if (!root) return nullptr;
  //   auto dummy = new Node(0), cur = dummy;
  //   stack<Node*> stk;
  //   auto node = root;
  //   while (node || stk.size()) {
  //     while (node) {
  //       stk.push(node);
  //       node = node->left;
  //     }

  //     node = stk.top(); stk.pop();
  //     cur->right = node;
  //     node->left = cur;

  //     cur = cur->right;
  //     node = node->right;
  //   }

  //   cur->right = dummy->right;
  //   dummy->right->left = cur;
  //   return dummy->right;
  // }

  Node* treeToDoublyList(Node* root) {
    if (!root) return nullptr;
    auto dummy = new Node(0), cur = dummy;
    dfs(root, cur);
    cur->right = dummy->right;
    cur->right->left = cur;
    return dummy->right;
  }

  void dfs(Node* p, Node*& cur) {
    if (!p) return;
    dfs(p->left, cur);
    cur->right = p;
    p->left = cur;
    cur = cur->right;
    dfs(p->right, cur);
  }
};
// @lc code=end
