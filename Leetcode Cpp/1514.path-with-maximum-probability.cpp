/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
class Solution {
 public:
  using PDI = pair<double, int>;
  double maxProbability(int n, vector<vector<int>>& es, vector<double>& prob,
                        int st, int ed) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    vector<double> w(m << 1);
    int idx = 0;
#define add(a, b, c) e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++
    for (int i = 0; i < m; i++) {
      int u = es[i][0], v = es[i][1];
      double pr = prob[i];
      add(u, v, pr), add(v, u, pr);
    }
    priority_queue<PDI> heap;
    heap.push({1.0, st});
    vector<bool> vis(n);
    vector<double> dist(n, 0.0);
    dist[st] = 1.0;
    while (heap.size()) {
      auto [pr, u] = heap.top();
      heap.pop();
      if (u == ed) return pr;
      if (vis[u]) continue;
      vis[u] = true;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        double p = w[i];
        if (!vis[v] && dist[v] < dist[u] * p) {
          dist[v] = dist[u] * p;
          heap.push({dist[v], v});
        }
      }
    }

    return 0.0;
  }
};
// @lc code=end
