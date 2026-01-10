/*
 * @lc app=leetcode id=2203 lang=cpp
 *
 * [2203] Minimum Weighted Subgraph With the Required Paths
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  ll minimumWeight(int n, vector<vector<int>> &es, int s1, int s2, int t) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1), w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
      e[idx] = a, ne[idx] = h[b], w[idx] = c, h[b] = idx++;
    };
    for (auto &e : es) add(e[0], e[1], e[2]);

    static constexpr ll INF = 9e18;
    vector<ll> d1(n, INF), d2(n, INF), dt(n, INF);
    auto dijkstra = [&](int st, auto &dist) {
      dist[st] = 0;
      using PLI = pair<ll, int>;
      priority_queue<PLI, vector<PLI>, greater<>> heap;
      heap.emplace(0, st);
      while (heap.size()) {
        auto [dis, u] = heap.top(); heap.pop();
        if (dis > dist[u]) continue;
        for (int i = h[u]; ~i; i = ne[i]) {
          if (&dist == &dt && i % 2 == 0) continue;
          if (&dist != &dt && i % 2) continue;
          int v = e[i], c = w[i];
          if (dist[v] > dis + c) {
            dist[v] = dis + c;
            heap.emplace(dist[v], v);
          }
        }
      }
    };

    dijkstra(s1, d1), dijkstra(s2, d2), dijkstra(t, dt);
    ll res = INF;
    for (int i = 0; i < n; i++)
      if (d1[i] < INF && d2[i] < INF && dt[i] < INF)
        res = min(res, d1[i] + d2[i] + dt[i]);
    return res == INF ? -1 : res;
  }
};
// @lc code=end
