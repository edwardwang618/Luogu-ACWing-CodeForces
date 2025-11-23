/*
 * @lc app=leetcode id=971 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
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
  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
    int idx = 0;
    vector<int> res;
    if (!dfs(root, idx, v, res)) return {-1};
    return res;
  }

  bool dfs(TreeNode* cur, int& idx, vector<int>& v, vector<int>& res) {
    if (!cur) return true;
    if (cur->val != v[idx]) return false;

    idx++;
    if (cur->left && cur->left->val != v[idx]) {
      swap(cur->left, cur->right);
      res.push_back(cur->val);
    }
    return dfs(cur->left, idx, v, res) && dfs(cur->right, idx, v, res);
  }
};
// @lc code=end
