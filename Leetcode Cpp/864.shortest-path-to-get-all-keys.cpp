/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
class Solution {
public:
  struct Node {
    int x, y;
    int keys;
  };
  int shortestPathAllKeys(vector<string> &g) {
    int m = g.size(), n = g[0].size();
    int nk = 0;
    queue<Node> q;
    auto is_key = [&](int x, int y) {
      return 'a' <= g[x][y] && g[x][y] <= 'z';
    };
    auto is_lock = [&](int x, int y) {
      return 'A' <= g[x][y] && g[x][y] <= 'Z';
    };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == '@') q.emplace(i, j, 0);
        else if (is_key(i, j)) nk++;
    bool vis[m][n][1 << nk];
    memset(vis, 0, sizeof vis);
    auto &st = q.front();
    vis[st.x][st.y][0] = true;
    int step = 0;
    while (q.size()) {
      step++;
      static int d[] = {1, 0, -1, 0, 1};
      for (int i = q.size(); i; i--) {
        auto [x, y, keys] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] != '#') {
            int ne_keys = keys;
            if (is_lock(nx, ny) && !(keys >> g[nx][ny] - 'A' & 1)) continue;
            if (is_key(nx, ny)) ne_keys |= 1 << g[nx][ny] - 'a';
            if (ne_keys == (1 << nk) - 1) return step;
            if (vis[nx][ny][ne_keys]) continue;
            vis[nx][ny][ne_keys] = true;
            q.emplace(nx, ny, ne_keys);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
