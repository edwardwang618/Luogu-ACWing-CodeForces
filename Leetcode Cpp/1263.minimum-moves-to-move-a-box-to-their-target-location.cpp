/*
 * @lc app=leetcode id=1263 lang=cpp
 *
 * [1263] Minimum Moves to Move a Box to Their Target Location
 */

// @lc code=start
class Solution {
 public:
  struct State {
    // box
    int x1, y1;
    // man
    int x2, y2;
  };

  const int N = 20;

  int minPushBox(vector<vector<char>>& g) {
    int m = g.size(), n = g[0].size();
    State begin;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (g[i][j] == 'B')
          begin.x1 = i, begin.y1 = j;
        else if (g[i][j] == 'S')
          begin.x2 = i, begin.y2 = j;

    int dist[N][N][N][N];
    bool vis[N][N][N][N];
    memset(dist, 0x3f, sizeof dist);
    dist[begin.x1][begin.y1][begin.x2][begin.y2] = 0;
    memset(vis, 0, sizeof vis);
    deque<State> dq;
    dq.push_back(begin);
    static int d[] = {-1, 0, 1, 0, -1};
    while (dq.size()) {
      auto t = dq.front();
      dq.pop_front();
      int x1 = t.x1, y1 = t.y1, x2 = t.x2, y2 = t.y2;
      int dis = dist[x1][y1][x2][y2];
      if (g[x1][y1] == 'T') return dis;
      if (vis[x1][y1][x2][y2]) continue;
      vis[x1][y1][x2][y2] = true;
      int ni = -1;
      for (int i = 0; i < 4; i++) {
        int nx2 = x2 + d[i], ny2 = y2 + d[i + 1];
        if (0 <= nx2 && nx2 < m && 0 <= ny2 && ny2 < n && g[nx2][ny2] != '#' &&
            dist[x1][y1][nx2][ny2] > dis) {
          if (nx2 == x1 && ny2 == y1) {
            ni = i;
            continue;
          }
          dist[x1][y1][nx2][ny2] = dis;
          dq.push_front({x1, y1, nx2, ny2});
        }
      }
      if (ni == -1) continue;
      int nx1 = x1 + d[ni], ny1 = y1 + d[ni + 1];
      if (0 <= nx1 && nx1 < m && 0 <= ny1 && ny1 < n && g[nx1][ny1] != '#' &&
          dist[nx1][ny1][x1][y1] > dis + 1) {
        dist[nx1][ny1][x1][y1] = dis + 1;
        dq.push_back({nx1, ny1, x1, y1});
      }
    }

    return -1;
  }
};
// @lc code=end
