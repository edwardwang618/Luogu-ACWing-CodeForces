/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> v;
    vector<vector<int>> res;
    dfs(1, k, n, v, res);
    return res;
  }

  void dfs(int u, int k, int sum, vector<int>& v, vector<vector<int>>& res) {
    if (v.size() == k) {
      if (!sum) res.push_back(v);
      return;
    }

    for (int i = u; i <= 9 - (k - v.size()) + 1; i++) {
      if (i > sum) return;
      v.push_back(i);
      dfs(i + 1, k, sum - i, v, res);
      v.pop_back();
    }
  }
};
// @lc code=end
