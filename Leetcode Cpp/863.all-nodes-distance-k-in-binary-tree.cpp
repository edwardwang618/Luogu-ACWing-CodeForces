/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
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
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if (!k) return {target->val};
    unordered_map<int, vector<int>> g;
    dfs(root, g);
    queue<int> q;
    q.push(target->val);
    vector<int> res;
    unordered_set<int> vis;
    vis.insert(target->val);
    while (q.size()) {
      k--;
      for (int i = q.size(); i; i--) {
        auto t = q.front(); q.pop();
        for (int ne : g[t]) {
          if (vis.count(ne)) continue;
          if (!k) res.push_back(ne);
          vis.insert(ne);
          q.push(ne);
        }
      }
      if (!k) return res;
    }

    return res;
  }

  void dfs(auto p, unordered_map<int, vector<int>>& g) {
    int x = p->val;
    if (p->left) {
      int y = p->left->val;
      g[x].push_back(y);
      g[y].push_back(x);
      dfs(p->left, g);
    }
    if (p->right) {
      int y = p->right->val;
      g[x].push_back(y);
      g[y].push_back(x);
      dfs(p->right, g);
    }
  }
};
// @lc code=end
