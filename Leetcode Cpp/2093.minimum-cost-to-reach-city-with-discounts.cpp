/*
 * @lc app=leetcode id=2093 lang=cpp
 *
 * [2093] Minimum Cost to Reach City With Discounts
 */

// @lc code=start
class Solution {
 public:
#define x first
#define y second
  using PII = pair<int, int>;
  vector<int> h, e, ne, w;
  int idx;
#define add(a, b, c) e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++

  int minimumCost(int n, vector<vector<int>> &es, int d) {
    int m = es.size() * 2;
    h.resize(n, -1);
    e.resize(m);
    ne.resize(m);
    w.resize(m);
    idx = 0;

    for (auto &ed : es) add(ed[0], ed[1], ed[2]), add(ed[1], ed[0], ed[2]);

    int dist[n][d + 1];
    memset(dist, 0x3f, sizeof dist);
    dist[0][d] = 0;
    auto cmp = [&](const PII &p1, const PII &p2) {
      return dist[p1.x][p1.y] > dist[p2.x][p2.y];
    };
    priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
    heap.push({0, d});
    bool vis[n][d + 1];
    memset(vis, 0, sizeof vis);
    while (heap.size()) {
      auto t = heap.top();
      heap.pop();
      int u = t.x, d = t.y;
      if (u == n - 1) return dist[u][d];
      if (vis[u][d]) continue;
      vis[u][d] = true;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!vis[v][d] && dist[v][d] > dist[u][d] + w[i]) {
          dist[v][d] = dist[u][d] + w[i];
          heap.push({v, d});
        }
        if (d && !vis[v][d - 1] && dist[v][d - 1] > dist[u][d] + w[i] / 2) {
          dist[v][d - 1] = dist[u][d] + w[i] / 2;
          heap.push({v, d - 1});
        }
      }
    }

    return -1;
  }
};
// @lc code=end
