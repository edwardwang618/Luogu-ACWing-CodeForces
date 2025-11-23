/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
  // vector<int> postorderTraversal(TreeNode* root) {
  //   vector<int> res;
  //   dfs(root, res);
  //   return res;
  // }

  // void dfs(TreeNode* root, vector<int>& res) {
  //   if (!root) return;
  //   dfs(root->left, res);
  //   dfs(root->right, res);
  //   res.push_back(root->val);
  // }

  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    auto cur = root;
    while (cur || stk.size()) {
      while (cur) {
        stk.push(cur);
        cur = cur->left ? cur->left : cur->right;
      }
      cur = stk.top(); stk.pop();
      res.push_back(cur->val);
      if (stk.size() && stk.top()->left == cur)
        cur = stk.top()->right;
      else cur = nullptr;
    }
    return res;
  }
};
// @lc code=end
