/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
 public:
  // vector<vector<int>> combinationSum(vector<int>& a, int t) {
  //   vector<vector<int>> res;
  //   sort(a.begin(), a.end());
  //   vector<int> v;
  //   dfs(v, 0, 0, t, a, res);
  //   return res;
  // }

  // void dfs(vector<int>& v, int s, int pos, int t, vector<int>& a,
  // vector<vector<int>>& res) {
  //   if (s == t) {
  //     res.push_back(v);
  //     return;
  //   }

  //   for (int i = pos; i < a.size(); i++) {
  //     if (s + a[i] > t) break;
  //     v.push_back(a[i]);
  //     dfs(v, s + a[i], i, t, a, res);
  //     v.pop_back();
  //   }
  // }

  vector<vector<int>> combinationSum(vector<int>& a, int t) {
    vector<vector<int>> res;
    vector<int> v;
    dfs(v, 0, 0, t, a, res);
    return res;
  }

  void dfs(vector<int>& v, int s, int pos, int t, vector<int>& a,
           vector<vector<int>>& res) {
    if (s == t) {
      res.push_back(v);
      return;
    }

    if (pos == a.size()) return;

    for (int i = 0; s + i * a[pos] <= t; i++) {
      dfs(v, s + i * a[pos], pos + 1, t, a, res);
      v.push_back(a[pos]);
    }
    for (int i = 0; s + i * a[pos] <= t; i++) v.pop_back();
  }
};
// @lc code=end
