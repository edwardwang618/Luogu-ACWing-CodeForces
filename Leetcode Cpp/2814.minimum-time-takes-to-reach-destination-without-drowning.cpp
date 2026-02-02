/*
 * @lc app=leetcode id=2814 lang=cpp
 *
 * [2814] Minimum Time Takes to Reach Destination Without Drowning
 */

// @lc code=start
class Solution {
public:
  int minimumSeconds(vector<vector<string>> &g) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) { return x * n + y; };
    auto in_bound = [&](int x, int y) {
      return 0 <= x && x < m && 0 <= y && y < n;
    };

    queue<int> q, q2;
    int st, ed;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (g[i][j] == "S")
          st = id(i, j);
        else if (g[i][j] == "D")
          ed = id(i, j);
        else if (g[i][j] == "*")
          q2.push(id(i, j));
      }

    q.push(st);
    g[st / n][st % n] = "V";

    int step = 0;
    while (q.size()) {
      step++;
      static constexpr int d[]{1, 0, -1, 0, 1};
      for (int _ = q2.size(); _--;) {
        int u = q2.front(); q2.pop();
        int x = u / n, y = u % n;
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (in_bound(nx, ny) &&
              (g[nx][ny] == "." || g[nx][ny] == "V" || g[nx][ny] == "S")) {
            g[nx][ny] = "*";
            q2.push(id(nx, ny));
          }
        }
      }
      for (int _ = q.size(); _--;) {
        int u = q.front(); q.pop();
        int x = u / n, y = u % n;
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (in_bound(nx, ny) && (g[nx][ny] == "." || g[nx][ny] == "D")) {
            if (g[nx][ny] == "D") return step;
            g[nx][ny] = "V";
            q.push(id(nx, ny));
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
