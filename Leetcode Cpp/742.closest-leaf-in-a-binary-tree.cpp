/*
 * @lc app=leetcode id=742 lang=cpp
 *
 * [742] Closest Leaf in a Binary Tree
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
  int findClosestLeaf(TreeNode* root, int k) {
    unordered_map<int, vector<int>> g;
    unordered_set<int> leaves;
    dfs(root, nullptr, g, leaves);
    if (leaves.count(k)) return k;
    queue<int> q;
    q.push(k);
    unordered_set<int> vis{k};
    while (q.size()) {
      auto t = q.front();
      q.pop();
      for (auto& ne : g[t]) {
        if (leaves.count(ne)) return ne;
        if (!vis.count(ne)) {
          vis.insert(ne);
          q.push(ne);
        }
      }
    }

    return -1;
  }

  void dfs(TreeNode* t, TreeNode* p, unordered_map<int, vector<int>>& g,
           unordered_set<int>& leaves) {
    if (!t) return;
    if (!t->left && !t->right) leaves.insert(t->val);
    if (p) g[t->val].push_back(p->val);
    if (t->left) {
      g[t->val].push_back(t->left->val);
      dfs(t->left, t, g, leaves);
    }
    if (t->right) {
      g[t->val].push_back(t->right->val);
      dfs(t->right, t, g, leaves);
    }
  }
};
// @lc code=end
