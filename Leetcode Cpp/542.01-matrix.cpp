/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
  using PII = pair<int, int>;
  vector<vector<int>> updateMatrix(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    vector<vector<int>> res(m, vector<int>(n, -1));
    queue<PII> q;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (!g[i][j]) {
          res[i][j] = 0;
          q.push({i, j});
        }
    
    int step = 0;
    while (q.size()) {
      step++;
      for (int i = q.size(); i; i--) {
        auto [x, y] = q.front(); q.pop();
        static int d[] = {1, 0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (0 <= nx && nx < m && 0 <= ny && ny < n && !~res[nx][ny]) {
            res[nx][ny] = res[x][y] + 1;
            q.push({nx, ny});
          }
        }
      }  
    }
    return res;
  }
};
// @lc code=end
