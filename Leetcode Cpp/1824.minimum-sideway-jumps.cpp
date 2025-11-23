/*
 * @lc app=leetcode id=1824 lang=cpp
 *
 * [1824] Minimum Sideway Jumps
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size() - 1;
    deque<PII> dq;
    dq.push_back({0, 2});
    bool vis[n + 1][3];
    memset(vis, 0, sizeof vis);
    int dist[n + 1][3];
    memset(dist, 0x3f, sizeof dist);
    dist[0][1] = 0;
    while (dq.size()) {
      auto t = dq.front();
      dq.pop_front();
      int x = t.first, y = t.second;
      if (x == n) return dist[x][y - 1];
      if (vis[x][y - 1]) continue;
      vis[x][y - 1] = true;
      if (obstacles[x + 1] != y && !vis[x + 1][y - 1] &&
          dist[x + 1][y - 1] > dist[x][y - 1]) {
        dist[x + 1][y - 1] = dist[x][y - 1];
        dq.push_back({x + 1, y});
      }
      for (int k = 1; k <= 3; k++)
        if (k != y && k != obstacles[x] && !vis[x][k - 1] &&
            dist[x][k - 1] > dist[x][y - 1] + 1) {
          dist[x][k - 1] = dist[x][y - 1] + 1;
          dq.push_back({x, k});
        }
    }

    return -1;
  }
};
// @lc code=end
