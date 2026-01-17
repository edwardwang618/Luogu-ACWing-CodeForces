/*
 * @lc app=leetcode id=2497 lang=cpp
 *
 * [2497] Maximum Star Sum of a Graph
 */

// @lc code=start
class Solution {
public:
  int maxStarSum(vector<int> &vs, vector<vector<int>> &es, int k) {
    int n = vs.size();
    vector<vector<int>> g(n);
    for (auto &e : es) {
      int u = e[0], v = e[1];
      if (vs[v] > 0) g[u].push_back(vs[v]);
      if (vs[u] > 0) g[v].push_back(vs[u]);
    }

    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
      auto &v = g[i];
      int n = v.size();
      if (k < n)
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<>{});
      int sum = vs[i];
      for (int j = 0; j < min(n, k); j++)
        sum += v[j];
      res = max(res, sum);
    }

    return res;
  }
};
// @lc code=end
