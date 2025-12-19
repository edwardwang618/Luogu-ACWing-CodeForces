/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
  void flatten(TreeNode *root) { dfs(root); }

  TreeNode *dfs(TreeNode *p) {
    if (!p)
      return nullptr;
    auto l_tail = dfs(p->left), r_tail = dfs(p->right);
    if (l_tail) {
      l_tail->right = p->right;
      p->right = p->left;
      p->left = nullptr;
    }

    return r_tail ? r_tail : (l_tail ? l_tail : p);
  }
};
// @lc code=end
