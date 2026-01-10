/*
 * @lc app=leetcode id=2699 lang=cpp
 *
 * [2699] Modify Graph Edge Weights
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &es,
                                         int start, int end, int target) {
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
    
    constexpr int INF = 1e9;
    vector<int> dist_rev(n, INF), dist(n, INF);
    auto dijkstra = [&](auto &dist, int start, int end) {
      dist[start] = 0;
      using PII = pair<int, int>;
      priority_queue<PII, vector<PII>, greater<>> heap;
      heap.emplace(0, start);
      while (heap.size()) {
        auto [dis, u] = heap.top(); heap.pop();
        if (dis > dist[u]) continue;
        if (u == end) return dis;
        for (int i = h[u]; ~i; i = ne[i]) {
          int v = e[i], c = w[i];
          if (!~c) {
            if (&dist == &dist_rev) c = 1;
            // dis + c + dis_rev[v] = target
            else {
              c = max(1, target - dis - dist_rev[v]);
              w[i] = w[i ^ 1] = c;
            }
            es[i / 2][2] = c;
          }
          if (dist[v] > dis + c) {
            dist[v] = dis + c;
            heap.emplace(dist[v], v);
          }
        }
      }
      return INF;
    };

    if (dijkstra(dist_rev, end, start) > target) return {};

    auto set_inf = [&]() {
      for (auto &e : es) if (!~e[2]) e[2] = INF;
    };
    if (dist_rev[start] == target) {
      set_inf();
      return es;
    }

    if (dijkstra(dist, start, end) == target) {
      set_inf();
      return es;
    }

    return {};
  }
};
// @lc code=end
