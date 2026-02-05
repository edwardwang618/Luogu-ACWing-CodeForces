/*
 * @lc app=leetcode id=2773 lang=cpp
 *
 * [2773] Height of Special Binary Tree
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
  int heightOfTree(TreeNode *root) {
    int res = 0;
    auto dfs = [&](this auto &&dfs, TreeNode *p, int dep) -> void {
      if (!p)
        return;
      res = max(res, dep);
      if (p->left && p->left->right != p)
        dfs(p->left, dep + 1);
      if (p->right && p->right->left != p)
        dfs(p->right, dep + 1);
    };
    dfs(root, 0);
    return res;
  }
};
// @lc code=end
