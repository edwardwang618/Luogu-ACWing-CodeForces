/*
 * @lc app=leetcode id=3123 lang=cpp
 *
 * [3123] Find Edges in Shortest Paths
 */

// @lc code=start
class Solution {
public:
  vector<bool> findAnswer(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1), w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1], c = e[2];
      add(a, b, c), add(b, a, c);
    }

    using ll = long long;
    static constexpr ll INF = 9e18;
    vector<ll> d1(n, INF), d2(n, INF);
    auto dijkstra = [&](int st, auto &dist) {
      dist[st] = 0;
      using PLI = pair<ll, int>;
      priority_queue<PLI, vector<PLI>, greater<>> heap;
      heap.emplace(0, st);
      while (heap.size()) {
        auto [dis, u] = heap.top();
        heap.pop();
        if (dis > dist[u]) continue;
        for (int i = h[u]; ~i; i = ne[i]) {
          int v = e[i];
          ll ndis = dis + w[i];
          if (dist[v] > ndis) {
            dist[v] = ndis;
            heap.emplace(dist[v], v);
          }
        }
      }
    };
    dijkstra(0, d1), dijkstra(n - 1, d2);

    vector<bool> res(m);
    for (int i = 0; i < m; i++) {
      auto &e = es[i];
      int u = e[0], v = e[1], c = e[2];
      ll dis = d1[n - 1];
      res[i] = (d1[u] < INF && d2[v] < INF && d1[u] + c + d2[v] == dis) ||
               (d1[v] < INF && d2[u] < INF && d1[v] + c + d2[u] == dis);
    }
    return res;
  }
};
// @lc code=end
