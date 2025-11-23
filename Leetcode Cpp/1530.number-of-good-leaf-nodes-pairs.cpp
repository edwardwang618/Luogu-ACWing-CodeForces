/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
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
  int countPairs(TreeNode *root, int dist) {
    int res = 0;
    dfs(root, dist, res);
    return res;
  }

  vector<int> dfs(TreeNode *cur, int dist, int &res) {
    if (!cur) return {};
    auto v1 = dfs(cur->left, dist, res), v2 = dfs(cur->right, dist, res);
    for (int i = 0, j = v2.size() - 1; i < v1.size(); i++) {
      while (j >= 0 && v1[i] + v2[j] > dist) j--;
      if (j < 0) break;
      res += j + 1;
    }

    vector<int> v;
    v.reserve(v1.size() + v2.size() + 1);
    if (!cur->left && !cur->right) v.push_back(1);
    for (int i = 0, j = 0; i < v1.size() || j < v2.size();) {
      if (j == v2.size() || i < v1.size() && v1[i] <= v2[j])
        v.push_back(v1[i++] + 1);
      else
        v.push_back(v2[j++] + 1);
    }
    return v;
  }
};
// @lc code=end
