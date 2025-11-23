/*
 * @lc app=leetcode id=270 lang=cpp
 *
 * [270] Closest Binary Search Tree Value
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
  int closestValue(TreeNode* root, double target) {
    int closest = root->val;
    const double epsilon = 1e-6;

    auto cur = root;
    while (cur) {
      double diff = abs(target - cur->val);
      double closestDiff = abs(target - closest);

      if (diff < closestDiff)
        closest = cur->val;

      else if (abs(diff - closestDiff) < epsilon)
        closest = min(closest, cur->val);

      if (target < cur->val)
        cur = cur->left;
      else
        cur = cur->right;
    }

    return closest;
  }
};
// @lc code=end
