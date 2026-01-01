/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
 */

// @lc code=start
class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &rs) {
    vector<int> cnt(n);
    vector<vector<bool>> g(n, vector<bool>(n));
    for (auto &r : rs) {
      int a = r[0], b = r[1];
      cnt[a]++;
      cnt[b]++;
      g[a][b] = g[b][a] = true;
    }

    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        int rk = cnt[i] + cnt[j];
        if (g[i][j]) {
          res = max(res, rk - 1);
        } else
          res = max(res, rk);
      }
    return res;
  }
};
// @lc code=end
