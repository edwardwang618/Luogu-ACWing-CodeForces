/*
 * @lc app=leetcode id=965 lang=cpp
 *
 * [965] Univalued Binary Tree
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
  bool isUnivalTree(TreeNode* root) {
    if (!root) return true;
    return dfs(root, root->val);
  }

  bool dfs(TreeNode* p, int v) {
    if (!p) return true;
    return p->val == v && dfs(p->left, v) && dfs(p->right, v);
  }
};
// @lc code=end
