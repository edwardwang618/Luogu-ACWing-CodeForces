/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 */

// @lc code=start
class Solution {
public:
  int latestDayToCross(int m, int n, vector<vector<int>> &cs) {
    auto id = [&](int x, int y) { return x * n + y; };
    int mn = m * n;
    vector<int> p(mn + 2);
    // mn top, mn + 1 bottom
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    auto merge = [&](int x, int y) {
      x = find(x), y = find(y);
      p[x] = y;
    };

    vector<vector<int>> g(m, vector<int>(n));
    for (int i = cs.size() - 1; i >= 0; i--) {
      auto &c = cs[i];
      int x = c[0] - 1, y = c[1] - 1;
      int idxy = id(x, y);
      g[x][y] = 1;
      static constexpr int d[]{1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny])
          merge(idxy, id(nx, ny));
      }
      if (!x)
        merge(idxy, mn);
      if (x == m - 1)
        merge(idxy, mn + 1);

      if (find(mn) == find(mn + 1))
        return i;
    }
    return 0;
  }
};
// @lc code=end
