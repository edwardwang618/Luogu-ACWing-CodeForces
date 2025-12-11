/*
 * @lc app=leetcode id=1559 lang=cpp
 *
 * [1559] Detect Cycles in 2D Grid
 */

// @lc code=start
class Solution {
public:
  bool containsCycle(vector<vector<char>> &g) {
    int m = g.size(), n = g[0].size();
    vector<int> p(m * n);
    iota(p.begin(), p.end(), 0);
    auto get = [&](int x, int y) { return x * n + y; };
    auto find = [&](auto &&self, int x) -> int {
      return p[x] == x ? x : p[x] = self(self, p[x]);
    };
    auto merge = [&](int x, int y) {
      int px = find(find, x), py = find(find, y);
      if (px == py)
        return false;
      p[px] = py;
      return true;
    };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (i + 1 < m && g[i][j] == g[i + 1][j] &&
            !merge(get(i, j), get(i + 1, j)))
          return true;
        if (j + 1 < n && g[i][j] == g[i][j + 1] &&
            !merge(get(i, j), get(i, j + 1)))
          return true;
      }
    return false;
  }
};
