/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    bool found = false;
    while (q.size()) {
      auto t = q.front(); q.pop();
      if (found && (t->left || t->right)) return false;
      if (!t->left && t->right) return false;
      if (!t->left || !t->right) found = true;
      if (t->left) q.push(t->left);
      if (t->right) q.push(t->right);
    }
    return true;
  }
};
// @lc code=end
