/*
 * @lc app=leetcode id=272 lang=cpp
 *
 * [272] Closest Binary Search Tree Value II
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
  vector<int> closestKValues(TreeNode* root, double t, int k) {
    deque<int> dq1, dq2;
    dfs(root, t, k, dq1, dq2);
    vector<int> res;
    while (res.size() < k) {
      if (dq2.empty() ||
          dq1.size() && abs(dq1.back() - t) <= abs(dq2.front() - t)) {
        res.push_back(dq1.back());
        dq1.pop_back();
      } else {
        res.push_back(dq2.front());
        dq2.pop_front();
      }
    }

    return res;
  }

  void dfs(TreeNode* root, double t, int k, deque<int>& dq1, deque<int>& dq2) {
    if (!root) return;
    dfs(root->left, t, k, dq1, dq2);
    if (root->val <= t) {
      dq1.push_back(root->val);
      if (dq1.size() > k) dq1.pop_front();
    } else if (dq2.size() < k)
      dq2.push_back(root->val);

    dfs(root->right, t, k, dq1, dq2);
  }
};
// @lc code=end
