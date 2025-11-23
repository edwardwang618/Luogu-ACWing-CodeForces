/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
  int sumNumbers(TreeNode* root) {
    int res = 0;
    dfs(root, 0, res);
    return res;
  }

  void dfs(TreeNode* p, int x, int& res) {
    if (!p) return;
    x = x * 10 + p->val;
    if (!p->left && !p->right) res += x;
    dfs(p->left, x, res);
    dfs(p->right, x, res);
  }
};
// @lc code=end
