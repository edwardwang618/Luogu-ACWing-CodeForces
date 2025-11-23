/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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
  struct Node {
    int mi, ma, sum;
    bool bin;
  };

  int res;
  int maxSumBST(TreeNode* root) {
    res = 0;
    dfs(root);
    return res;
  }

  Node dfs(TreeNode* cur) {
    if (!cur) return {INT_MAX, INT_MIN, 0, true};
    auto l = dfs(cur->left), r = dfs(cur->right);
    int sum = cur->val + l.sum + r.sum;
    Node t = {min(cur->val, l.mi), max(cur->val, r.ma), sum, false};
    if (l.bin && r.bin && l.ma < cur->val && cur->val < r.mi) {
      res = max(res, sum);
      t.bin = true;
    }
    return t;
  }
};
// @lc code=end
