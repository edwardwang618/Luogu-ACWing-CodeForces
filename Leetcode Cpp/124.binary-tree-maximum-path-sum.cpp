/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
  int maxPathSum(TreeNode *root) {
    int res = INT_MIN;
    dfs(root, res);
    return res;
  }

  int dfs(TreeNode *root, int &res) {
    if (!root) return 0;
    int l = max(0, dfs(root->left, res)), r = max(0, dfs(root->right, res));
    res = max(res, l + r + root->val);
    return root->val + max(l, r);
  }
};
// @lc code=end
