/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
// class Solution {
// public:
//   using PII = pair<int, int>;
//   int swimInWater(vector<vector<int>> &g) {
//     int l = 0, r = 0, n = g.size();
//     for (int i = 0; i < n; i++)
//       for (int j = 0; j < n; j++) r = max(r, g[i][j]);

//     auto bfs = [&](int M) {
//       if (n == 1) return true;
//       if (g[0][0] > M) return false;
//       vector<vector<bool>> vis(n, vector<bool>(n));
//       vis[0][0] = true;
//       queue<PII> q;
//       q.emplace(0, 0);
//       while (q.size()) {
//         auto [x, y] = q.front(); q.pop();
//         static int d[] = {1, 0, -1, 0, 1};
//         for (int k = 0; k < 4; k++) {
//           int nx = x + d[k], ny = y + d[k + 1];
//           if (0 <= nx && nx < n && 0 <= ny && ny < n && g[nx][ny] <= M) {
//             if (nx == n - 1 && ny == n - 1) return true;
//             if (!vis[nx][ny]) {
//               vis[nx][ny] = true;
//               q.emplace(nx, ny);
//             }
//           }
//         }
//       }
//       return false;
//     };
//     while (l < r) {
//       int mid = l + r >> 1;
//       if (bfs(mid)) r = mid;
//       else l = mid + 1;
//     }
//     return l;
//   }
// };

// class Solution {
// public:
//   struct Edge {
//     int x, y;
//     int len;
//     bool operator<(const Edge& e) const {
//       return len < e.len;
//     }
//   };

//   int swimInWater(vector<vector<int>> &g) {
//     int n = g.size(), m = n * n;
//     if (n == 1) return g[0][0];
//     auto id = [&](int x, int y) {
//       return x * n + y;
//     };
//     vector<Edge> es;
//     es.reserve(2 * n * (n - 1));
//     for (int i = 0; i < n; i++)
//       for (int j = 0; j < n; j++) {
//         int idij = id(i, j);
//         if (i + 1 < n) es.emplace_back(idij, id(i + 1, j), max(g[i][j], g[i + 1][j]));
//         if (j + 1 < n) es.emplace_back(idij, id(i, j + 1), max(g[i][j], g[i][j + 1]));
//       }
//     sort(es.begin(), es.end());
//     vector<int> p(m);
//     iota(p.begin(), p.end(), 0);
//     auto find = [&](auto &&self, int x) -> int {
//       return x == p[x] ? x : p[x] = self(self, p[x]);
//     };
//     for (auto &e : es) {
//       int x = e.x, y = e.y;
//       int px = find(find, x), py = find(find, y);
//       if (px == py) continue;
//       p[px] = py;
//       if (find(find, 0) == find(find, m - 1)) return e.len;
//     }
//     return -1;
//   }
// };

class Solution {
public:
  using PII = pair<int, int>;
  int swimInWater(vector<vector<int>> &g) {
    int n = g.size();
    vector<vector<int>> dist(n, vector<int>(n, 2e9));
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(g[0][0], 0);
    dist[0][0] = g[0][0];
    while (heap.size()) {
      auto [dis, id] = heap.top(); heap.pop();
      int x = id / n, y = id % n;
      if (dis > dist[x][y]) continue;
      if (x == n - 1 && y == n - 1) return dist[x][y];
      static int d[] = {1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
          int nd = max(dis, g[nx][ny]);
          if (nd < dist[nx][ny]) {
            dist[nx][ny] = nd;
            heap.emplace(nd, nx * n + ny);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
