/*
 * @lc app=leetcode id=3157 lang=cpp
 *
 * [3157] Find the Level of Tree with Minimum Sum
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
  int minimumLevel(TreeNode *root) {
    using ll = long long;
    queue<TreeNode *> q;
    q.push(root);
    int res;
    ll min_sum = 9e18;
    int level = 0;
    while (q.size()) {
      level++;
      ll sum = 0;
      for (int _ = q.size(); _--; ) {
        auto *t = q.front(); q.pop();
        sum += t->val;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      if (sum < min_sum) res = level, min_sum = sum;
    }

    return res;
  }
};
// @lc code=end
