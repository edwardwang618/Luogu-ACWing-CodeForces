/*
 * @lc app=leetcode id=2664 lang=cpp
 *
 * [2664] The Knight’s Tour
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
    vector<vector<int>> g(m, vector<int>(n, -1));
    static int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    static int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    auto in_bound = [&](int x, int y) {
      return 0 <= x && x < m && 0 <= y && y < n;
    };
    auto degree = [&](int x, int y) {
      int cnt = 0;
      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (in_bound(nx, ny))
          cnt++;
      }
      return cnt;
    };

    int total = m * n;
    auto dfs = [&](this auto &&dfs, int x, int y, int step) -> bool {
      g[x][y] = step;
      if (step == total - 1) return true;
      using T = tuple<int, int, int>;
      vector<T> moves;
      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (in_bound(nx, ny) && !~g[nx][ny])
          moves.emplace_back(degree(nx, ny), nx, ny);
      }
      sort(moves.begin(), moves.end());
      for (auto &[_, nx, ny] : moves)
        if (dfs(nx, ny, step + 1)) return true;
      g[x][y] = -1;
      return false;
    };

    dfs(r, c, 0);
    return g;
  }
};
// @lc code=end
