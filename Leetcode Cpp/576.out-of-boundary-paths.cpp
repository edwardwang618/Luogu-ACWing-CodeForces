/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
class Solution {
public:
  int findPaths(int m, int n, int max_move, int sr, int sc) {
    using ll = long long;
    static constexpr int MOD = 1e9 + 7;
    // vector f(m * n * max_move, -1);
    // auto id = [&](int x, int y, int step) {
    //   return x * n * max_move + y * max_move + step;
    // };
    // auto dfs = [&](this auto &&dfs, int x, int y, int step) -> ll {
    //   if (x < 0 || x >= m || y < 0 || y >= n) return 1;
    //   if (step == max_move) return 0;
    //   int idxy = id(x, y, step);
    //   if (~f[idxy]) return f[idxy];
    //   ll res = 0;
    //   static constexpr int d[]{1, 0, -1, 0, 1};
    //   for (int k = 0; k < 4; k++) {
    //     int nx = x + d[k], ny = y + d[k + 1];
    //     res = (res + dfs(nx, ny, step + 1)) % MOD;
    //   }
    //   return f[idxy] = res;
    // };
    // return dfs(sr, sc, 0);

    int f[2][m][n];
    memset(f, 0, sizeof f);
    for (int k = 1; k <= max_move; k++)
      for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++) {
          f[k & 1][x][y] = 0;
          static constexpr int d[]{1, 0, -1, 0, 1};
          for (int p = 0; p < 4; p++) {
            int nx = x + d[p], ny = y + d[p + 1];
            if (0 <= nx && nx < m && 0 <= ny && ny < n)
              f[k & 1][x][y] = (f[k & 1][x][y] + f[k - 1 & 1][nx][ny]) % MOD;
            else f[k & 1][x][y]++;
          }
        }
    return f[max_move & 1][sr][sc];
  }
};
// @lc code=end
