/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
  vector<int> findFrequentTreeSum(TreeNode *root) {
    int max_freq = 0;
    unordered_map<int, int> mp;

    auto dfs = [&](this auto &&dfs, auto root) -> int {
      if (!root) return 0;
      int sum = root->val + dfs(root->left) + dfs(root->right);
      if (max_freq < ++mp[sum]) max_freq++;
      return sum;
    };
    dfs(root);
    vector<int> res;
    for (auto [k, v] : mp) if (v == max_freq) res.push_back(k);
    return res;
  }
};
// @lc code=end
