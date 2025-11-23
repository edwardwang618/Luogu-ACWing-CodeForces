/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
  int goodNodes(TreeNode* root) {
    int res = 0;
    dfs(root, INT_MIN, res);
    return res;
  }

  void dfs(TreeNode* cur, int maxv, int &res) {
    if (!cur) return;
    if (cur->val >= maxv) res++;
    int x = max(maxv, cur->val);
    dfs(cur->left, x, res);
    dfs(cur->right, x, res);
  }
};
// @lc code=end
