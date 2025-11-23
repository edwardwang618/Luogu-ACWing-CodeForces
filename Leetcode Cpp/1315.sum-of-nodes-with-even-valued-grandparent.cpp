/*
 * @lc app=leetcode id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
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
  int sumEvenGrandparent(TreeNode* root) { return dfs(root, 0, root, root); }

  int dfs(TreeNode* cur, int depth, TreeNode* p, TreeNode* gp) {
    if (!cur) return 0;
    int sum = 0;
    if (depth >= 2 && gp->val % 2 == 0) sum += cur->val;
    return sum + dfs(cur->left, depth + 1, cur, p) +
           dfs(cur->right, depth + 1, cur, p);
  }
};
// @lc code=end
