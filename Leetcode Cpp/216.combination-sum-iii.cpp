/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> v;
    auto dfs = [&](this auto &&dfs, int u, int k, int sum) -> void {
      if (v.size() == k) {
        if (!sum) res.push_back(v);
        return;
      }

      for (int i = u; i <= 9 - (k - v.size()) + 1; i++) {
        if (i > sum) return;
        v.push_back(i);
        dfs(i + 1, k, sum - i);
        v.pop_back();
      }
    };
    dfs(1, k, n);
    return res;
  }
};
// @lc code=end
