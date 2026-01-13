/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution {
public:
  int maxDistance(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    using PII = pair<int, int>;
    queue<PII> q;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) q.emplace(i, j);
    if (q.size() == m * n || q.empty()) return -1;
    int res = -1;
    while (q.size()) {
      res++;
      for (int i = q.size(); i; i--) {
        auto [x, y] = q.front(); q.pop();
        static constexpr int d[] = {1, 0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (0 <= nx && nx < m && 0 <= ny && ny < n && !g[nx][ny]) {
            g[nx][ny] = 1;
            q.emplace(nx, ny);
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
