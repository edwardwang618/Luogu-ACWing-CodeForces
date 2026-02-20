/*
 * @lc app=leetcode id=3831 lang=cpp
 *
 * [3831] Median of a Binary Search Tree Level
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
  int levelMedian(TreeNode *root, int level) {
    vector<int> v;
    queue<TreeNode*> q{{root}};
    while (q.size()) {
      for (int _ = q.size(); _--;) {
        auto t = q.front(); q.pop();
        if (!level) v.push_back(t->val);
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      level--;
    }
    if (v.empty()) return -1;
    int pos = v.size() / 2;
    nth_element(v.begin(), v.begin() + pos, v.end());
    return v[pos];
  }
};
// @lc code=end
