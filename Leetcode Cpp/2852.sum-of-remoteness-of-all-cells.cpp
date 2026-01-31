/*
 * @lc app=leetcode id=2852 lang=cpp
 *
 * [2852] Sum of Remoteness of All Cells
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  ll sumRemoteness(vector<vector<int>> &g) {
    int n = g.size();
    ll tot = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (~g[i][j]) tot += g[i][j];
    
    ll res = 0;
    auto dfs = [&](this auto &&dfs, int x, int y, int &cnt, ll &sum) -> void {
      cnt++;
      sum += g[x][y];
      g[x][y] = -1;
      static constexpr int d[]{1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && g[nx][ny] > 0)
          dfs(nx, ny, cnt, sum);
      }
    };
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (!~g[i][j]) continue;
        int cnt = 0;
        ll sum = 0;
        dfs(i, j, cnt, sum);
        res += cnt * (tot - sum);
      }
    return res;
  }
};
// @lc code=end
