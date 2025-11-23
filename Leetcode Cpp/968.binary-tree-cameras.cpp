/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
  int minCameraCover(TreeNode* root) {
    auto res = dfs(root);
    return min(res[1], res[2]);
  }

  vector<int> dfs(TreeNode* cur) {
    if (!cur) return {0, 0, INT_MAX / 2};
    auto l = dfs(cur->left), r = dfs(cur->right);
    return {min(l[1], l[2]) + min(r[1], r[2]),
            min(l[2] + min(r[1], r[2]), r[2] + min(l[1], l[2])),
            1 + min(l[0], min(l[1], l[2])) + min(r[0], min(r[1], r[2]))};
  }
};
// @lc code=end
