/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
  int res = 0;
  int longestZigZag(TreeNode* root) {
    dfs(root);
    return res;
  }

  pair<int, int> dfs(TreeNode* cur) {
    if (!cur) return {0, 0};
    auto p1 = dfs(cur->left), p2 = dfs(cur->right);
    res = max(res, max(p1.second, p2.first));
    return {1 + p1.second, 1 + p2.first};
  }
};
// @lc code=end
