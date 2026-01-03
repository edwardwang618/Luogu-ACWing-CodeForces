/*
 * @lc app=leetcode id=2689 lang=cpp
 *
 * [2689] Extract Kth Character From The Rope Tree
 */

// @lc code=start
/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr),
 * right(nullptr) {} RopeTreeNode(int x) : len(x), val(""), left(nullptr),
 * right(nullptr) {} RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode
 * *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
public:
  char getKthCharacter(RopeTreeNode *root, int k) {
    auto get_len = [&](auto *p) -> int {
      if (!p) return 0;
      if (!p->left && !p->right) return p->val.size();
      return p->len;
    };
    while (root) {
      if (!root->left && !root->right) return root->val[k - 1];
      int len = get_len(root->left);
      if (k <= len) root = root->left;
      else {
        k -= len;
        root = root->right;
      }
    }
    return ' ';
  }
};
// @lc code=end
