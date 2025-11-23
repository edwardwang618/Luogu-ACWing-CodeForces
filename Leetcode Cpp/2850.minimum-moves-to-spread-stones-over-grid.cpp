/*
 * @lc app=leetcode id=2850 lang=cpp
 *
 * [2850] Minimum Moves to Spread Stones Over Grid
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  int minimumMoves(vector<vector<int>>& g) {
    vector<int> a;
    vector<PII> pos;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        if (!g[i][j])
          a.push_back(-1), pos.push_back({i, j});
        else
          for (int k = 0; k < g[i][j] - 1; k++)
            a.push_back(1), pos.push_back({i, j});
      }
    return dfs(0, a, pos);
  }

  int dfs(int u, auto& a, auto& pos) {
    while (u < a.size() && !a[u]) u++;
    if (u == a.size()) return 0;
    int res = 2e9;
    for (int i = u + 1; i < a.size(); i++)
      if (a[u] * a[i] < 0) {
        a[i] += a[u];
        auto& [x1, y1] = pos[u];
        auto& [x2, y2] = pos[i];
        res = min(res, abs(x1 - x2) + abs(y1 - y2) + dfs(u + 1, a, pos));
        a[i] -= a[u];
      }
    return res;
  }
};
// @lc code=end
