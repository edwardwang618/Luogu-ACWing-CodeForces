/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    auto l = root->left, r = root->right;
    int a = 1, b = 1;
    while (l) l = l->left, a++;
    while (r) r = r->right, b++;
    if (a == b) return (1 << a) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
// @lc code=end
