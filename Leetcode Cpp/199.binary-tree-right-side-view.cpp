/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    dfs(0, root, res);
    return res;
  }

  void dfs(int u, TreeNode* cur, vector<int>& res) {
    if (!cur) return;
    if (u >= res.size()) res.push_back(cur->val);
    else res[u] = cur->val;
    dfs(u + 1, cur->left, res);
    dfs(u + 1, cur->right, res);
  }
};
// @lc code=end
