/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
 public:
  // vector<vector<int>> subsets(vector<int>& a) {
  //   vector<vector<int>> res;
  //   vector<int> v;
  //   dfs(0, a, v, res);
  //   return res;
  // }

  // static void dfs(int u, auto& a, auto& v, auto& res) {
  //   res.push_back(v);
  //   for (int i = u; i < a.size(); i++) {
  //     v.push_back(a[i]);
  //     dfs(i + 1, a, v, res);
  //     v.pop_back();
  //   }
  // }

  // vector<vector<int>> subsets(vector<int>& a) {
  //   int n = a.size();
  //   vector<vector<int>> res;
  //   res.reserve(1 << n);
  //   for (int i = 0; i < 1 << n; i++) {
  //     vector<int> v;
  //     for (int k = 0; k < n; k++)
  //       if (i >> k & 1) v.push_back(a[k]);
  //     res.push_back(move(v));
  //   }
  //   return res;
  // }

  vector<vector<int>> subsets(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> res{{}};
    res.reserve(1 << n);
    for (int x : a) {
      int sz = res.size();
      for (int i = 0; i < sz; i++) {
        res.push_back(res[i]);
        res.back().push_back(x);
      }
    }
    return res;
  }
};
// @lc code=end
