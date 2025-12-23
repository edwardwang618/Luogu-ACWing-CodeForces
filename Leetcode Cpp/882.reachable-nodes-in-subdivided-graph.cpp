/*
 * @lc app=leetcode id=882 lang=cpp
 *
 * [882] Reachable Nodes In Subdivided Graph
 */

// @lc code=start
class Solution {
public:
  using PII = pair<int, int>;
  int reachableNodes(vector<vector<int>> &es, int M, int n) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1), w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1], c = e[2];
      add(a, b, c + 1), add(b, a, c + 1);
    }

    vector<int> dist(n, 2e9);
    dist[0] = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(0, 0);
    while (heap.size()) {
      auto [d, u] = heap.top(); heap.pop();
      if (d > dist[u]) continue;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        if (dist[v] > dist[u] + c) {
          dist[v] = dist[u] + c;
          heap.emplace(dist[v], v);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < n; i++) if (dist[i] <= M) res++;
    for (auto &e : es) {
      int a = e[0], b = e[1], c = e[2];
      res += min(c, max(M - dist[a], 0) + max(M -dist[b], 0));
    }
    return res;
  }
};
// @lc code=end
