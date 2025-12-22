/*
 * @lc app=leetcode id=803 lang=cpp
 *
 * [803] Bricks Falling When Hit
 */

// @lc code=start
class Solution {
public:
  vector<int> hitBricks(vector<vector<int>> &g, vector<vector<int>> &hs) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int i, int j) { return i * n + j; };

    int TOP = m * n;
    vector<int> p(m * n + 1, -1), sz(m * n + 1, 0);

    auto find = [&](auto &&self, int x) -> int {
      return x == p[x] ? x : p[x] = self(self, p[x]);
    };
    auto merge = [&](int x, int y) {
      int px = find(find, x), py = find(find, y);
      if (px == py)
        return;
      p[px] = py;
      sz[py] += sz[px];
    };
    auto topSize = [&]() { return sz[find(find, TOP)]; };

    static int d[] = {1, 0, -1, 0, 1};

    auto build_brick = [&](int x, int y) {
      g[x][y] = 1;
      int xx = id(x, y);
      p[xx] = xx;
      sz[xx] = 1;
      if (!x)
        merge(xx, TOP);
    };

    auto four_merge = [&](int x, int y) {
      // g[x][y] must be 1 and DSU node must be initialized
      int idxy = id(x, y);
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny])
          merge(idxy, id(nx, ny));
      }
    };

    int n_hs = hs.size();
    vector<int> res(n_hs);
    vector<bool> has_brick(n_hs);

    for (int i = 0; i < n_hs; i++) {
      int x = hs[i][0], y = hs[i][1];
      if (g[x][y]) {
        has_brick[i] = true;
        g[x][y] = 0;
      }
    }

    p[TOP] = TOP;
    sz[TOP] = 0;

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) {
          int x = id(i, j);
          p[x] = x;
          sz[x] = 1;
        }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j]) {
          int idij = id(i, j);
          if (!i)
            merge(idij, TOP);
          if (i + 1 < m && g[i + 1][j])
            merge(idij, id(i + 1, j));
          if (j + 1 < n && g[i][j + 1])
            merge(idij, id(i, j + 1));
        }

    for (int i = n_hs - 1; i >= 0; i--) {
      int x = hs[i][0], y = hs[i][1];
      if (!has_brick[i])
        continue;

      int before = topSize();
      build_brick(x, y);
      four_merge(x, y);
      int after = topSize();
      if (after != before) res[i] = after - before - 1;
    }

    return res;
  }
};
// @lc code=end
