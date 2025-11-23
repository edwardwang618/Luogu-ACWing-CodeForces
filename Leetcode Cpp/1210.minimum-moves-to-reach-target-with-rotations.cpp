/*
 * @lc app=leetcode id=1210 lang=cpp
 *
 * [1210] Minimum Moves to Reach Target with Rotations
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    int x, y, d;
    bool operator==(const Node& p) const {
      return x == p.x && y == p.y && d == p.d;
    }
  };

  int minimumMoves(vector<vector<int>>& g) {
    int n = g.size();
    if (g[n - 1][n - 1] == 1 || g[n - 1][n - 2] == 1) return -1;
    auto nhash = [](const Node& p) {
      return hash<int>()(p.x) ^ hash<int>()(p.y) ^ hash<int>()(p.d);
    };

    queue<Node> q;
    q.push({0, 0, 0});
    bool vis[n][n][2];
    memset(vis, 0, sizeof vis);
    vis[0][0][0] = true;
    auto can_go = [&](int x, int y) {
      return 0 <= x && x < g.size() && 0 <= y && y < g[0].size() && !g[x][y];
    };
    Node end{n - 1, n - 2, 0};
    int res = 0;
    while (q.size()) {
      res++;
      for (int _ = q.size(); _; _--) {
        auto t = q.front();
        q.pop();
        int x = t.x, y = t.y, d = t.d;
        int hx, hy;
        if (!d) hx = x, hy = y + 1;
        else hx = x + 1, hy = y;

        // right
        if (can_go(hx, hy + 1) && can_go(x, y + 1)) {
          Node ne = {x, y + 1, d};
          if (ne == end) return res;
          if (!vis[x][y + 1][d]) {
            vis[x][y + 1][d] = true;
            q.push(ne);
          }
        }

        // down
        if (can_go(hx + 1, hy) && can_go(x + 1, y)) {
          Node ne = {x + 1, y, d};
          if (ne == end) return res;
          if (!vis[x + 1][y][d]) {
            vis[x + 1][y][d] = true;
            q.push(ne);
          }
        }

        if (can_go(x + 1, y + 1)) {
          if (!d && can_go(x + 1, y)) {
            Node ne = {x, y, 1};
            if (!vis[x][y][1]) {
              vis[x][y][1] = true;
              q.push(ne);
            }
          }
          if (d && can_go(x, y + 1)) {
            Node ne = {x, y, 0};
            if (!vis[x][y][0]) {
              vis[x][y][0] = true;
              q.push(ne);
            }
          }
        }
      }
    }

    return -1;
  }
};
// @lc code=end
