/*
 * @lc app=leetcode id=2258 lang=cpp
 *
 * [2258] Escape the Spreading Fire
 */

// @lc code=start
class Solution {
public:
  int maximumMinutes(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    static constexpr int INF = 1e9;
    vector<vector<int>> fire(m, vector<int>(n, INF));
    static constexpr int d[]{1, 0, -1, 0, 1};
    auto in_bound = [&](int x, int y) {
      return 0 <= x && x < m && 0 <= y && y < n;
    };
    using PII = pair<int, int>;
    {
      queue<PII> q;
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          if (g[i][j] == 1) {
            q.emplace(i, j);
            fire[i][j] = 0;
          }
      while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (in_bound(nx, ny) && g[nx][ny] != 2 && fire[nx][ny] == INF) {
            fire[nx][ny] = fire[x][y] + 1;
            q.emplace(nx, ny);
          }
        }
      }
    }

    auto f = [&](int t) {
      if (m == 1 && n == 1)
        return true;
      if (t >= fire[0][0])
        return false;
      vector<vector<bool>> vis(m, vector<bool>(n));
      vis[0][0] = true;
      queue<PII> q;
      q.emplace(0, 0);
      int step = 0;
      while (q.size()) {
        step++;
        for (int _ = q.size(); _--;) {
          auto [x, y] = q.front();
          q.pop();
          for (int k = 0; k < 4; k++) {
            int nx = x + d[k], ny = y + d[k + 1];
            if (in_bound(nx, ny) && g[nx][ny] != 2) {
              if (nx == m - 1 && ny == n - 1 && t + step <= fire[m - 1][n - 1])
                return true;
              if (t + step < fire[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.emplace(nx, ny);
              }
            }
          }
        }
      }
      return false;
    };

    if (!f(0)) return -1;
    if (fire[m - 1][n - 1] == INF) return INF;
    int l = 0, r = fire[m - 1][n - 1];
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (f(mid))
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }
};
// @lc code=end
