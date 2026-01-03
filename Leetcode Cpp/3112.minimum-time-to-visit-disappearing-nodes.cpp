/*
 * @lc app=leetcode id=3112 lang=cpp
 *
 * [3112] Minimum Time to Visit Disappearing Nodes
 */

// @lc code=start
class Solution {
public:
  vector<int> minimumTime(int n, vector<vector<int>> &es,
                          vector<int> &disappear) {
    int m = es.size(), idx = 0;
    vector<int> h(n, -1), e(m << 1), ne(m << 1), w(m << 1);
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1], c = e[2];
      add(a, b, c), add(b, a, c);
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
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        int ndis = dis + c;
        if (ndis < disappear[v] && ndis < dist[v]) {
          dist[v] = ndis;
          heap.emplace(ndis, v);
        }
      }
    }

    for (int &x : dist) if (x == INF) x = -1;
    return dist;
  }
};
// @lc code=end
