/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  using PLI = pair<ll, int>;
  int countPaths(int n, vector<vector<int>> &es) {
    static constexpr int MOD = 1e9 + 7;
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1), w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1], c = e[2];
      add(a, b, c);
      add(b, a, c);
    }
    vector<ll> dist(n, numeric_limits<ll>::max());
    vector<int> cnt(n);
    dist[0] = 0;
    cnt[0] = 1;
    vector<bool> vis(n);
    priority_queue<PLI, vector<PLI>, greater<>> heap;
    heap.emplace(0, 0);
    while (heap.size()) {
      auto [d, u] = heap.top(); heap.pop();
      if (u == n - 1) return cnt[n - 1];
      if (vis[u]) continue;
      vis[u] = true;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        if (dist[v] > d + c) {
          dist[v] = d + c;
          heap.emplace(dist[v], v);
          cnt[v] = cnt[u];
        } else if (dist[v] == dist[u] + c) 
          cnt[v] = (cnt[v] + cnt[u]) % MOD;
      }
    }

    return -1;
  }
};
// @lc code=end
