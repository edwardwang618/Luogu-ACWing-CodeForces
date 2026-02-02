/*
 * @lc app=leetcode id=3552 lang=cpp
 *
 * [3552] Grid Teleportation Traversal
 */

// @lc code=start
class Solution {
public:
  int minMoves(vector<string> &g) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) {
      return x * n + y;
    };
    if (!id(m - 1, n - 1)) return 0;
    vector<vector<int>> pos(26);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (isalpha(g[i][j])) pos[g[i][j] - 'A'].push_back(id(i, j));

    int ed = id(m - 1, n - 1);
    queue<int> q;
    if (isalpha(g[0][0])) {
      int idx = g[0][0] - 'A';
      for (int nn : pos[idx]) {
        if (nn == ed) return 0;
        q.push(nn);
        g[nn / n][nn % n] = '#';
      }
    } else {
      q.push(0);
      g[0][0] = '#';
    }
    int step = 0;
    while (q.size()) {
      step++;
      for (int _ = q.size(); _--; ) {
        int u = q.front(); q.pop();
        int x = u / n, y = u % n;
        static constexpr int d[]{1, 0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] != '#') {
            int nid = id(nx, ny);
            if (nid == ed) return step;
            if (isalpha(g[nx][ny])) {
              int idx = g[nx][ny] - 'A';
              for (int nn : pos[idx]) {
                if (nn == ed) return step;
                if (nn == nid) continue;
                q.push(nn);
                g[nn / n][nn % n] = '#';
              }
              pos[idx].clear();
            }
            q.push(nid);
            g[nx][ny] = '#';
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
