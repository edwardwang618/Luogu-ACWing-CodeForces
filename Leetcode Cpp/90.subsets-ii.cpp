/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
// class Solution {
//  public:
//   vector<vector<int>> subsetsWithDup(vector<int>& a) {
//     sort(a.begin(), a.end());
//     vector<vector<int>> res;
//     vector<int> v;
//     dfs(0, v, a, res);
//     return res;
//   }

//   void dfs(int u, vector<int>& v, vector<int>& a, vector<vector<int>>& res) {
//     res.push_back(v);
//     for (int i = u; i < a.size(); i++) {
//       if (i > u && a[i] == a[i - 1]) continue;
//       v.push_back(a[i]);
//       dfs(i + 1, v, a, res);
//       v.pop_back();
//     }
//   }
// };

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& a) {
    sort(a.begin(), a.end());
    vector<vector<int>> res;
    vector<int> v;
    dfs(0, v, a, res);
    return res;
  }

  void dfs(int u, vector<int>& v, vector<int>& a, vector<vector<int>>& res) {
    if (u == a.size()) {
      res.push_back(v);
      return;
    }

    int cnt = 0;
    while (u + cnt < a.size() && a[u + cnt] == a[u]) cnt++;

    for (int i = 0; i <= cnt; i++) {
      dfs(u + cnt, v, a, res);
      v.push_back(a[u]);
    }

    v.resize(v.size() - cnt - 1);
  }
};
// @lc code=end
