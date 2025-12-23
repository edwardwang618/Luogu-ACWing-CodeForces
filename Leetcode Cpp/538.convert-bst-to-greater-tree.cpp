/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
  TreeNode *convertBST(TreeNode *root) {
    int sum = 0;
    auto dfs = [&](auto &&self, auto root) -> void {
      if (!root) return;
      self(self, root->right);
      root->val += sum;
      sum = root->val;
      self(self, root->left);
    };
    dfs(dfs, root);
    return root;
  }
};
// @lc code=end
