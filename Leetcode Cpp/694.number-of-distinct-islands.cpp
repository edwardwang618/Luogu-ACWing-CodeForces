/*
 * @lc app=leetcode id=694 lang=cpp
 *
 * [694] Number of Distinct Islands
 */

// @lc code=start
class Solution {
public:
  int numDistinctIslands(vector<vector<int>> &g) {
    static constexpr int d[]{1, 0, -1, 0, 1};
    unordered_set<string> st;
    int m = g.size(), n = g[0].size();
    static constexpr array<char, 4> a{'0', '1', '2', '3'};
    auto dfs = [&](this auto &&dfs, int x, int y, string &s) -> void {
      g[x][y] = -1;
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] == 1) {
          s += a[k];
          dfs(nx, ny, s);
        }
      }
      s += '#';
    };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == 1) {
          string s;
          dfs(i, j, s);
          st.insert(s);
        }
    return st.size();
  }
};
// @lc code=end
