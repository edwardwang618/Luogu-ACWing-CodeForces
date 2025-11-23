/*
 * @lc app=leetcode id=156 lang=cpp
 *
 * [156] Binary Tree Upside Down
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
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    return dfs(root); 
  }

  TreeNode* dfs(TreeNode* p) {
    if (!p) return nullptr;
    if (!p->left) return p;
    TreeNode* res = dfs(p->left);
    p->left->left = p->right;
    p->left->right = p;
    p->left = p->right = nullptr;
    return res;
  }
};
// @lc code=end
