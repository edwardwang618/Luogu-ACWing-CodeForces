/*
 * @lc app=leetcode id=1928 lang=cpp
 *
 * [1928] Minimum Cost to Reach Destination in Time
 */

// @lc code=start
class Solution {
public:
  int minCost(int maxTime, vector<vector<int>> &es, vector<int> &fees) {
    int n = fees.size();
    static constexpr int INF = 2e9;
    vector<vector<int>> f(maxTime + 1, vector<int>(n, INF));
    for (int i = 0; i <= maxTime; i++)
      f[i][0] = fees[0];
    for (int t = 1; t <= maxTime; t++)
      for (auto &e : es) {
        int a = e[0], b = e[1], time = e[2];
        if (t >= time) {
          f[t][a] = min(f[t][a], f[t - time][b] + fees[a]);
          f[t][b] = min(f[t][b], f[t - time][a] + fees[b]);
        }
      }

    int res = INF;
    for (int i = 0; i <= maxTime; i++)
      res = min(res, f[i][n - 1]);
    return res == INF ? -1 : res;
  }
};
// @lc code=end
