/*
 * @lc app=leetcode id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
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
  TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*> q;
    if (root) q.push(root);
    int depth = 0;
    while (q.size()) {
      vector<TreeNode*> v;
      depth++;
      for (int i = q.size(); i; i--) {
        auto t = q.front();
        q.pop();
        if (depth % 2 == 0) v.push_back(t);
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }

      for (int i = 0, j = v.size() - 1; i < j; i++, j--)
        swap(v[i]->val, v[j]->val);
    }

    return root;
  }
};
// @lc code=end
