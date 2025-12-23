/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
class Solution {
public:
  using PII = pair<int, int>;
  int trapRainWater(vector<vector<int>> &hs) {
    int m = hs.size(), n = hs[0].size();
    auto id = [&](int x, int y) {
      return x * n + y;
    };
    vector<vector<bool>> vis(m, vector<bool>(n));
    priority_queue<PII, vector<PII>, greater<>> heap;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (!i || i == m - 1 || !j || j == n - 1) {
          heap.emplace(hs[i][j], id(i, j));
          vis[i][j] = true;
        }
    
    int res = 0;
    while (heap.size()) {
      auto [h, idxy] = heap.top(); heap.pop();
      int x = idxy / n, y = idxy % n;
      static int d[] = {1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && !vis[nx][ny]) {
          res += max(0, h - hs[nx][ny]);
          vis[nx][ny] = true;
          heap.emplace(max(h, hs[nx][ny]), id(nx, ny));
        }
      }
    }
    return res;
  }
};
// @lc code=end
