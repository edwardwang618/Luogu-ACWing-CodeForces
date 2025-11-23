/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
  // vector<int> inorderTraversal(TreeNode* root) {
  //   vector<int> res;
  //   stack<TreeNode*> stk;
  //   auto cur = root;
  //   while (cur || stk.size()) {
  //     while (cur) {
  //       stk.push(cur);
  //       cur = cur->left;
  //     }
  //     cur = stk.top();
  //     stk.pop();
  //     res.push_back(cur->val);
  //     cur = cur->right;
  //   }
  //   return res;
  // }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    auto cur = root;
    while (cur) {
      if (!cur->left) {
        res.push_back(cur->val);
        cur = cur->right;
        continue;
      }

      auto left = cur->left;
      while (left->right && left->right != cur) left = left->right;
      if (!left->right) {
        left->right = cur;
        cur = cur->left;
      } else {
        left->right = nullptr;
        res.push_back(cur->val);
        cur = cur->right;
      }
    }
    return res;
  }
};
// @lc code=end
