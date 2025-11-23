/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v1, v2;
    dfs(root1, v1);
    dfs(root2, v2);
    return v1 == v2;
  }

  void dfs(TreeNode* r, vector<int>& v) {
    if (!r) return;
    if (!r->left && !r->right) v.push_back(r->val);
    dfs(r->left, v);
    dfs(r->right, v);
  }
};
// @lc code=end
