/*
 * @lc app=leetcode id=1932 lang=cpp
 *
 * [1932] Merge BSTs to Create Single BST
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
  TreeNode *canMerge(vector<TreeNode *> &trees) {
    unordered_map<int, TreeNode *> roots;
    unordered_map<int, int> leaf_cnt;
    auto is_leaf = [](auto x) { return x && !x->left && !x->right; };
    for (auto *t : trees)
      roots[t->val] = t;
    for (auto *t : trees) {
      if (is_leaf(t->left))
        leaf_cnt[t->left->val]++;
      if (is_leaf(t->right))
        leaf_cnt[t->right->val]++;
    }

    TreeNode *root = nullptr;
    for (auto *t : trees) {
      if (leaf_cnt.find(t->val) == leaf_cnt.end()) {
        if (root)
          return nullptr;
        root = t;
      }
    }
    if (!root)
      return nullptr;

    unordered_set<int> used;
    used.insert(root->val);
    auto dfs = [&](this auto &&dfs, auto *root, int lo, int hi) {
      if (!root)
        return true;
      if (!(lo < root->val && root->val < hi))
        return false;

      if (!root->left && !root->right) { // leaf
        auto it = roots.find(root->val);
        if (it != roots.end() && it->second != root) {
          auto *g = it->second;
          auto [it, ins] = used.emplace(g->val);
          if (!ins)
            return false;
          root->left = g->left;
          root->right = g->right;
          delete g;
        }
      }
      return dfs(root->left, lo, root->val) && dfs(root->right, root->val, hi);
    };
    if (!dfs(root, INT_MIN, INT_MAX) || used.size() != trees.size())
      return nullptr;
    return root;
  }
};

// @lc code=end
