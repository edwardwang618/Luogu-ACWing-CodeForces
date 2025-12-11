/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
  int pathSum(TreeNode *root, int t) {
    unordered_map<ll, int> mp{{0, 1}};
    int res = 0;
    dfs(root, 0, t, mp, res);
    return res;
  }

  static void dfs(auto p, ll sum, int t, auto &mp, int &res) {
    if (!p) return;
    sum += p->val;
    if (auto it = mp.find(sum - t); it != mp.end())
      res += it->second;
    ++mp[sum];
    dfs(p->left, sum, t, mp, res);
    dfs(p->right, sum, t, mp, res);
    auto it = mp.find(sum);
    if (!--it->second) mp.erase(it);
  }
};
// @lc code=end
