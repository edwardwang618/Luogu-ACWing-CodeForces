/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> pre;
  int MOD = 1e9 + 7;
  int ways(vector<string>& ps, int k) {
    int m = ps.size(), n = ps[0].size();
    pre = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        pre[i][j] = (ps[i - 1][j - 1] == 'A' ? 1 : 0) + pre[i - 1][j] +
                    pre[i][j - 1] - pre[i - 1][j - 1];
    vector<vector<vector<int>>> f(m, vector<vector<int>>(n, vector<int>(k, -1)));
    return dfs(0, 0, m, n, k - 1, f);
  }

  int dfs(int x, int y, int m, int n, int k, vector<vector<vector<int>>>& f) {
    if (x == m || y == n) return 0;
    if (~f[x][y][k]) return f[x][y][k];
    if (!k) return f[x][y][k] = check(x, y, m - 1, n - 1) ? 1 : 0;
    int res = 0;
    for (int i = x; i < m; i++)
      if (check(x, y, i, n - 1))
        res = (res + dfs(i + 1, y, m, n, k - 1, f)) % MOD;
    for (int j = y; j < n; j++)
      if (check(x, y, m - 1, j))
        res = (res + dfs(x, j + 1, m, n, k - 1, f)) % MOD;

    return f[x][y][k] = res;
  }

  bool check(int x1, int y1, int x2, int y2) {
    return pre[x2 + 1][y2 + 1] - pre[x1][y2 + 1] - pre[x2 + 1][y1] +
               pre[x1][y1] > 0;
  }
};
// @lc code=end
