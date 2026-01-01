/*
 * @lc app=leetcode id=2583 lang=cpp
 *
 * [2583] Kth Largest Sum in a Binary Tree
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
  using ll = long long;
  ll kthLargestLevelSum(TreeNode *root, int k) {
    priority_queue<ll, vector<ll>, greater<>> heap;
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      ll sum = 0;
      for (ll i = q.size(); i; i--) {
        auto t = q.front(); q.pop();
        sum += t->val;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      if (heap.size() < k) heap.push(sum);
      else if (sum > heap.top()) {
        heap.pop();
        heap.push(sum);
      }
    }
    return heap.size() == k ? heap.top() : -1;
  }
};
// @lc code=end
