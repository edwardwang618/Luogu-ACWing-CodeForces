/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
  vector<TreeNode *> generateTrees(int n) {
    auto dfs = [&](this auto &&dfs, int l, int r) -> vector<TreeNode *> {
      if (l > r)
        return {nullptr};
      vector<TreeNode *> res;
      for (int i = l; i <= r; i++)
        for (auto *left : dfs(l, i - 1))
          for (auto *right : dfs(i + 1, r))
            res.push_back(new TreeNode(i, left, right));

      return res;
    };
    return dfs(1, n);
  }
};
// @lc code=end
