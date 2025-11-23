/*
 * @lc app=leetcode id=2471 lang=cpp
 *
 * [2471] Minimum Number of Operations to Sort a Binary Tree by Level
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
  int minimumOperations(TreeNode* root) {
    if (!root) return 0;
    int res = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      vector<int> v, ids;
      for (int i = q.size(); i--;) {
        auto t = q.front();
        q.pop();
        v.push_back(t->val);
        ids.push_back(ids.size());
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }

      sort(ids.begin(), ids.end(), [&](int i, int j) { return v[i] < v[j]; });
      for (int i = 0; i < ids.size(); i++) {
        if (ids[i] == -1) continue;
        int x = ids[i], len = 0;
        while (~ids[x]) {
          len++;
          int y = x;
          x = ids[y];
          ids[y] = -1;
        }

        res += len - 1;
      }
    }

    return res;
  }
};
// @lc code=end
