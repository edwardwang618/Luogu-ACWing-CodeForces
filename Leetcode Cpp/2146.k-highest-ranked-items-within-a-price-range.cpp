/*
 * @lc app=leetcode id=2146 lang=cpp
 *
 * [2146] K Highest Ranked Items Within a Price Range
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>> &g,
                                          vector<int> &ps, vector<int> &st,
                                          int k) {
    int m = g.size(), n = g[0].size();
    using PII = pair<int, int>;
    vector<vector<int>> dist(m, vector<int>(n, -1));
    auto cmp = [&](const PII &p1, const PII &p2) {
      auto [x1, y1] = p1;
      auto [x2, y2] = p2;
      if (dist[x1][y1] != dist[x2][y2]) return dist[x1][y1] < dist[x2][y2];
      if (g[x1][y1] != g[x2][y2]) return g[x1][y1] < g[x2][y2];
      if (x1 != x2) return x1 < x2;
      return y1 < y2;
    };
    priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
    queue<PII> q;
    int bx = st[0], by = st[1];
    q.emplace(bx, by);
    dist[bx][by] = 0;
    int lo = ps[0], hi = ps[1];
    while (q.size()) {
      auto [x, y] = q.front(); q.pop();
      static constexpr int d[]{1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny]) {
          if (!~dist[nx][ny]) {
            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx, ny);
          }
        }
      }
    }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (int x = g[i][j]; ~dist[i][j] && lo <= x && x <= hi) {
          if (heap.size() < k) heap.emplace(i, j);
          else {
            if (cmp(PII{i, j}, heap.top())) {
              heap.pop();
              heap.emplace(i, j);
            }
          }
        }
    vector<vector<int>> res;
    res.reserve(heap.size());
    while (heap.size()) {
      auto [x, y] = heap.top(); heap.pop();
      res.push_back({x, y});
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
