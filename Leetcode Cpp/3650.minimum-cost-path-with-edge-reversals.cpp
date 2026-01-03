/*
 * @lc app=leetcode id=3650 lang=cpp
 *
 * [3650] Minimum Cost Path with Edge Reversals
 */

// @lc code=start
class Solution {
public:
  int minCost(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1), w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1], c = e[2];
      add(a, b, c);
      add(b, a, 2 * c);
    }

    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(0, 0);
    constexpr int INF = 2e9;
    vector<int> dist(n, INF);
    dist[0] = 0;
    while (heap.size()) {
      auto [dis, u] = heap.top(); heap.pop();
      if (dis > dist[u]) continue;
      if (u == n - 1) return dis;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        if (dist[v] > dis + c) {
          dist[v] = dis + c;
          heap.emplace(dist[v], v);
        }
      }
    }
    return -1;
  }
};
// @lc code=end
