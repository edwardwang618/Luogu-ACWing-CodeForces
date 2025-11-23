/*
 * @lc app=leetcode id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                          TreeNode* target) {
    return dfs(original, cloned, target);
  }

  TreeNode* dfs(TreeNode* t1, TreeNode* t2, TreeNode* p) {
    if (!t1) return nullptr;
    if (t1 == p) return t2;
    auto l = dfs(t1->left, t2->left, p);
    if (l) return l;
    return dfs(t1->right, t2->right, p);
  }
};
// @lc code=end
