/*
 * @lc app=leetcode id=366 lang=cpp
 *
 * [366] Find Leaves of Binary Tree
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
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    dfs(root, res);
    return res;
  }

  int dfs(TreeNode* root, vector<vector<int>>& res) {
    if (!root) return -1;
    int he = 1 + max(dfs(root->left, res), dfs(root->right, res));
    if (he >= res.size()) res.push_back({});
    res[he].push_back(root->val);
    return he;
  }
};
// @lc code=end
