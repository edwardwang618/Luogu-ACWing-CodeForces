/*
 * @lc app=leetcode id=3419 lang=cpp
 *
 * [3419] Minimize the Maximum Edge Weight of Graph
 */

// @lc code=start
class Solution {
public:
  // int minMaxWeight(int n, vector<vector<int>> &es, int threshold) {
  //   int m = es.size();
  //   vector<int> h(n, -1), e(m), ne(m), w(m);
  //   int idx = 0;
  //   auto add = [&](int a, int b, int c) {
  //     e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
  //   };
  //   int r = 0;
  //   for (auto &e : es) {
  //     int a = e[0], b = e[1], c = e[2];
  //     add(b, a, c);
  //     r = max(r, c);
  //   }

  //   auto check = [&](int len) {
  //     vector<bool> vis(n);
  //     auto dfs = [&](this auto &&dfs, int u, int len) -> int {
  //       if (vis[u]) return 0;
  //       vis[u] = true;
  //       int cnt = 1;
  //       for (int i = h[u]; ~i; i = ne[i]) {
  //         int v = e[i];
  //         if (w[i] <= len) cnt += dfs(v, len);
  //       }
  //       return cnt;
  //     };
  //     return dfs(0, len) == n;
  //   };

  //   int l = 0;
  //   while (l < r) {
  //     int mid = l + r >> 1;
  //     if (check(mid)) r = mid;
  //     else l = mid + 1;
  //   }

  //   if (check(l)) return l;
  //   return -1;
  // }

  int minMaxWeight(int n, vector<vector<int>> &es, int threshold) {
    int m = es.size();
    vector<int> h(n, -1), e(m), ne(m), w(m);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1], c = e[2];
      add(b, a, c);
    }
    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(0, 0);
    vector<bool> vis(n);
    int res = 0;
    while (heap.size()) {
      auto [dis, u] = heap.top(); heap.pop();
      if (vis[u]) continue;
      vis[u] = true;
      res = max(res, dis);
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        if (!vis[v]) heap.emplace(c, v);
      }
    }
    for (bool x : vis) if (!x) return -1;
    return res;
  }
};
// @lc code=end
