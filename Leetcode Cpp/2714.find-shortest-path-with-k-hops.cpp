/*
 * @lc app=leetcode id=2714 lang=cpp
 *
 * [2714] Find Shortest Path with K Hops
 */

// @lc code=start
class Solution {
public:
  int shortestPathWithHops(int n, vector<vector<int>> &es, int s, int d,
                           int k) {
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
    static constexpr int INF = 2e9;
    vector<vector<int>> dist(k + 1, vector<int>(n, INF));
    dist[0][s] = 0;
    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<>> heap;
    heap.emplace(0, 0, s);
    while (heap.size()) {
      auto [dis, hop, u] = heap.top(); heap.pop();
      if (dis > dist[hop][u]) continue;
      if (u == d) return dis;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        if (dist[hop][v] > dis + c) {
          dist[hop][v] = dis + c;
          heap.emplace(dist[hop][v], hop, v);
        }
        if (hop < k && dist[hop + 1][v] > dis) {
          dist[hop + 1][v] = dis;
          heap.emplace(dist[hop + 1][v], hop + 1, v);
        }
      }
    }
    return -1;
  }
};
// @lc code=end
