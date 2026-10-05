/*
 * @lc app=leetcode id=3283 lang=cpp
 *
 * [3283] Maximum Number of Moves to Kill All Pawns
 */

// @lc code=start
class Solution {
public:
  int maxMoves(int kx, int ky, vector<vector<int>> &ps) {
    auto bfs = [&](int sx, int sy) {
      static constexpr int dx[]{-2, -2, -1, -1, 1, 1, 2, 2};
      static constexpr int dy[]{-1, 1, -2, 2, -2, 2, -1, 1};
      vector<vector<int>> dist(50, vector<int>(50, -1));
      dist[sx][sy] = 0;
      using PII = pair<int, int>;
      queue<PII> q{{{sx, sy}}};
      while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
          int nx = x + dx[k], ny = y + dy[k];
          if (0 <= nx && nx < 50 && 0 <= ny && ny < 50 && !~dist[nx][ny]) {
            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx, ny);
          }
        }
      }
      return dist;
    };

    int n = ps.size();
    vector<vector<int>> cost(n + 1, vector<int>(n));

    auto d = bfs(kx, ky);
    for (int i = 0; i < n; i++)
      cost[0][i] = d[ps[i][0]][ps[i][1]];

    for (int i = 0; i < n; i++) {
      auto d = bfs(ps[i][0], ps[i][1]);
      for (int j = 0; j < n; j++)
        cost[i + 1][j] = d[ps[j][0]][ps[j][1]];
    }
    vector<vector<vector<int>>> f(
        2, vector<vector<int>>(n + 1, vector<int>(1 << n, -1)));
    auto dfs = [&](this auto &&dfs, int pos, int mask, bool is_alice) -> int {
      if (!mask)
        return 0;
      if (~f[is_alice][pos][mask])
        return f[is_alice][pos][mask];
      static constexpr int INF = 2e9;
      int res = is_alice ? 0 : INF;
      for (int i = 0; i < n; i++) {
        if (!(mask >> i & 1))
          continue;
        int tot = cost[pos][i] + dfs(i + 1, mask ^ (1 << i), !is_alice);
        res = is_alice ? max(res, tot) : min(res, tot);
      }
      return f[is_alice][pos][mask] = res;
    };
    return dfs(0, (1 << n) - 1, true);
  }
};
// @lc code=end
