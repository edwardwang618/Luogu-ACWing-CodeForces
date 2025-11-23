/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
 public:
  vector<int> p, sz;
  int maxAreaOfIsland(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size(), mn = m * n;
    p.resize(mn);
    sz.resize(mn);
    for (int i = 0; i < mn; i++) p[i] = i, sz[i] = 1;
    auto f = [&](int x, int y) { return x * n + y; };
    auto merge = [&](int x, int y) {
      int px = find(x), py = find(y);
      if (px == py) return;
      p[px] = py, sz[py] += sz[px];
    };
    int res = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (!g[i][j]) continue;
        int x = f(i, j);
        if (i >= 1 && g[i - 1][j] == 1) merge(x, f(i - 1, j));
        if (i + 1 < m && g[i + 1][j] == 1) merge(x, f(i + 1, j));
        if (j >= 1 && g[i][j - 1] == 1) merge(x, f(i, j - 1));
        if (j + 1 < n && g[i][j + 1] == 1) merge(x, f(i, j + 1));
      }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) res = max(res, sz[f(i, j)]);
    return res;
  }

  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }
};
// @lc code=end
