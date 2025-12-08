/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& a, int t) {
    sort(a.begin(), a.end(), greater<>());
    vector<vector<int>> res;
    vector<int> v;
    dfs(v, 0, t, a, res);
    return res;
  }

  static void dfs(vector<int>& v, int pos, int t, vector<int>& a,
           vector<vector<int>>& res) {
    if (!t) {
      res.push_back(v);
      return;
    }

    if (pos == a.size()) return;

    int sz = v.size();
    for (; t >= 0; t -= a[pos]) {
      dfs(v, pos + 1, t, a, res);
      v.push_back(a[pos]);
    }
    v.resize(sz);
  }
};
// @lc code=end
