/*
 * @lc app=leetcode id=2473 lang=cpp
 *
 * [2473] Minimum Cost to Buy Apples
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  vector<ll> minCost(int n, vector<vector<int>> &es, vector<int> &cost, int k) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1), w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0] - 1, b = e[1] - 1, c = e[2];
      add(a, b, c), add(b, a, c);
    }
    using PLI = pair<ll, int>;
    priority_queue<PLI, vector<PLI>, greater<>> heap;
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
      heap.emplace(cost[i], i);
      res[i] = cost[i];
    }

    while (heap.size()) {
      auto [c, u] = heap.top(); heap.pop();
      if (c > res[u]) continue;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (c + (k + 1) * w[i] < res[v]) {
          res[v] = c + (k + 1) * w[i];
          heap.emplace(res[v], v);
        }
      }
    }
    return res;
  }
};
// @lc code=end
