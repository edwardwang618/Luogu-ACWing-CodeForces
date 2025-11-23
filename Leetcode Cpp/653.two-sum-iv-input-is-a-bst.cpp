/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> st;
    return dfs(root, k, st);
  }

  bool dfs(auto root, int k, auto& st) {
    if (!root) return false;
    if (st.count(k - root->val)) return true;
    st.insert(root->val);
    return dfs(root->left, k, st) || dfs(root->right, k, st);
  }
};
// @lc code=end
