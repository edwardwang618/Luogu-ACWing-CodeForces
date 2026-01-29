/*
 * @lc app=leetcode id=3568 lang=cpp
 *
 * [3568] Minimum Moves to Clean the Classroom
 */

// @lc code=start
class Solution {
public:
  int minMoves(vector<string> &g, int E) {
    // pos, lit, energy
    using T = tuple<int, int, int>;
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) { return x * n + y; };
    int pos, lit_idx = 0;
    vector<vector<int>> lit_id(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == 'S') pos = id(i, j);
        else if (g[i][j] == 'L') lit_id[i][j] = lit_idx++;

    if (!lit_idx) return 0;
    const int FULL = (1 << lit_idx) - 1;
    queue<T> q;
    q.emplace(pos, FULL, E);
    bool vis[m * n][FULL + 1][E + 1];
    memset(vis, 0, sizeof vis);
    vis[pos][FULL][E] = true;
    int step = 0;
    while (q.size()) {
      step++;
      for (int _ = q.size(); _--;) {
        auto [pos, lit, en] = q.front(); q.pop();
        if (!en) continue;
        int x = pos / n, y = pos % n;
        static constexpr int d[]{1, 0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1], npos = id(nx, ny);
          if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] != 'X') {
            int nlit = lit, nen = en - 1;
            if (g[nx][ny] == 'L') {
              int cur_lit_id = lit_id[nx][ny];
              if (lit >> cur_lit_id & 1) {
                nlit = lit ^ (1 << cur_lit_id);
                if (!nlit) return step;
              }
            } else if (g[nx][ny] == 'R') nen = E;

            if (vis[npos][nlit][nen]) continue;
            vis[npos][nlit][nen] = true;
            q.emplace(npos, nlit, nen);
          }
        }
      }
    }

    return -1;
  }
};
// @lc code=end
