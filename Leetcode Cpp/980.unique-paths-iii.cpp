/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    int sx, sy, ed_st = 0;
    auto f = [&](int x, int y) { return x * n + y; };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == 1)
          sx = i, sy = j, ed_st |= 1 << f(i, j);
        else if (!g[i][j])
          ed_st |= 1 << f(i, j);

    int res = 0;
    dfs(sx, sy, 0, ed_st, f, g, res);
    return res;
  }

  void dfs(int x, int y, int vis, int ed_st, auto& f, vector<vector<int>>& g,
           int& res) {
    int m = g.size(), n = g[0].size();
    if (g[x][y] == 2) {
      res += vis == ed_st;
      return;
    }

    vis |= 1 << f(x, y);
    static int d[] = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int nx = x + d[i], ny = y + d[i + 1];
      if (0 <= nx && nx < m && 0 <= ny && ny < n) {
        if (!~g[nx][ny] || (vis >> f(nx, ny) & 1)) continue;
        dfs(nx, ny, vis, ed_st, f, g, res);
      }
    }
  }

  // int uniquePathsIII(vector<vector<int>>& g) {
  //   int m = g.size(), n = g[0].size();
  //   int sx, sy, ex, ey, ed_st = 0;
  //   auto h = [&](int x, int y) { return x * n + y; };
  //   for (int i = 0; i < m; i++)
  //     for (int j = 0; j < n; j++) {
  //       if (~g[i][j]) ed_st |= 1 << h(i, j);
  //       if (g[i][j] == 1)
  //         sx = i, sy = j;
  //       else if (g[i][j] == 2)
  //         ex = i, ey = j;
  //     }
  //   unordered_map<int, vector<int>> f;
  //   return dfs(1 << h(sx, sy), sx, sy, ed_st, h(ex, ey), f, h, g);
  // }

  // int dfs(int cur_st, int x, int y, int ed_st, int ed_idx, auto& f, auto& h,
  //         vector<vector<int>>& g) {
  //   int m = g.size(), n = g[0].size();
  //   int cur_idx = h(x, y);
  //   if (!f.count(cur_st)) f[cur_st] = vector<int>(m * n, -1);
  //   int& res = f[cur_st][cur_idx];
  //   if (~res) return res;
  //   if (cur_idx == ed_idx) return res = cur_st == ed_st;
  //   res = 0;
  //   static int d[] = {-1, 0, 1, 0, -1};
  //   for (int i = 0; i < 4; i++) {
  //     int nx = x + d[i], ny = y + d[i + 1];
  //     if (0 <= nx && nx < m && 0 <= ny && ny < n) {
  //       int ne_idx = h(nx, ny);
  //       if (!~g[nx][ny] || (cur_st >> ne_idx & 1)) continue;
  //       res += dfs(cur_st | (1 << ne_idx), nx, ny, ed_st, ed_idx, f, h, g);
  //     }
  //   }
  //   return res;
  // }
};
// @lc code=end
