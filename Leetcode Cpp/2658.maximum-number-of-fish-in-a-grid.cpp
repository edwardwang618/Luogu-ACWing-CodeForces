/*
 * @lc app=leetcode id=2658 lang=cpp
 *
 * [2658] Maximum Number of Fish in a Grid
 */

// @lc code=start
class Solution {
public:
  int findMaxFish(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) {
      return x * n + y;
    };
    vector<int> p(m * n), sz(m * n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    auto merge = [&](int x1, int y1, int x2, int y2) {
      int a = id(x1, y1), b = id(x2, y2);
      int pa = find(a), pb = find(b);
      if (pa == pb) return;
      p[pa] = pb;
      sz[pb] += sz[pa];
    };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        sz[id(i, j)] = g[i][j];
    
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (!g[i][j]) continue;
        if (i && g[i - 1][j]) merge(i, j, i - 1, j);
        if (j && g[i][j - 1]) merge(i, j, i, j - 1);
      }
    return *max_element(sz.begin(), sz.end());
  }
};
// @lc code=end
