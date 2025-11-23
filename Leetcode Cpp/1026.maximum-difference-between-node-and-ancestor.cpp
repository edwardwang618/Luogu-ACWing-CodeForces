/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
  int maxAncestorDiff(TreeNode* root) {
    int res = 0;
    dfs(root, 1e5 + 1, -1, res);
    return res;
  }

  void dfs(TreeNode* cur, int minv, int maxv, int& res) {
    if (!cur) return;
    if (~maxv) {
      res = max(abs(cur->val - minv), res);
      res = max(abs(cur->val - maxv), res);
    }
    minv = min(minv, cur->val);
    maxv = max(maxv, cur->val);
    dfs(cur->left, minv, maxv, res);
    dfs(cur->right, minv, maxv, res);
  }
};
// @lc code=end
