/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    optional<int> res;
    while (q.size()) {
      for (int i = q.size(); i; i--) {
        auto t = q.front(); q.pop();
        if (!res) res = t->val;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      if (q.empty()) break;
      else res.reset();
    }
    return *res;
  }
};
// @lc code=end
