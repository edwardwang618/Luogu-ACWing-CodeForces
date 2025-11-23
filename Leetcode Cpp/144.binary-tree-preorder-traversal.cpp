/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
  // vector<int> preorderTraversal(TreeNode* root) {
  //   vector<int> res;
  //   dfs(root, res);
  //   return res;
  // }

  // void dfs(TreeNode* root, vector<int>& res) {
  //   if (!root) return;
  //   res.push_back(root->val);
  //   dfs(root->left, res);
  //   dfs(root->right, res);
  // }

  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    auto cur = root;
    while (cur || stk.size()) {
      while (cur) {
        res.push_back(cur->val);
        if (cur->right) stk.push(cur->right);
        cur = cur->left;
      }
      if (stk.size()) {
        cur = stk.top();
        stk.pop();
      }
    }
    return res;
  }
};
// @lc code=end
