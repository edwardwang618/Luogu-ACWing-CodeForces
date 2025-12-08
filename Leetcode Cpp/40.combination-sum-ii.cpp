/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &a, int t) {
    vector<vector<int>> res;
    sort(a.rbegin(), a.rend());

    vector<int> v;
    v.reserve(a.size());
    dfs(0, t, a, v, res);
    return res;
  }

  static void dfs(int u, int t, vector<int> &a, vector<int> &v,
           vector<vector<int>> &res) {
    if (!t) {
      res.push_back(v);
      return;
    }

    for (int i = u; i < a.size(); i++) {
      if (i > u && a[i] == a[i - 1]) continue;

      if (t >= a[i]) {
        v.push_back(a[i]);
        dfs(i + 1, t - a[i], a, v, res);
        v.pop_back();
      }
    }
  }
};
// @lc code=end
