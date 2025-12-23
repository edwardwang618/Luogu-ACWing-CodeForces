/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
public:
  int nearestExit(vector<vector<char>> &g, vector<int> &en) {
    int m = g.size(), n = g[0].size();
    auto in_bound = [&](int x, int y) {
      return 0 <= x && x < m && 0 <= y && y < n;
    };
    auto id = [&](int x, int y) {
      return x * n + y;
    };
    int st = id(en[0], en[1]);
    int res = 0;
    queue<int> q;
    q.push(st);
    vector<bool> vis(m * n);
    vis[st] = true;
    while (q.size()) {
      res++;
      for (int i = q.size(); i; i--) {
        int u = q.front(); q.pop();
        int x = u / n, y = u % n;
        static int d[] = {1, 0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          int nid = id(nx, ny);
          if (in_bound(nx, ny) && g[nx][ny] == '.' && !vis[nid]) {
            if (!nx || nx == m - 1 || !ny || ny == n - 1) return res;
            vis[nid] = true;
            q.push(nid);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
