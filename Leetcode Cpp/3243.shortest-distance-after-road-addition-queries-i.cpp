/*
 * @lc app=leetcode id=3243 lang=cpp
 *
 * [3243] Shortest Distance After Road Addition Queries I
 */

// @lc code=start
class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &qs) {
    int m = n - 1 + qs.size();
    vector<int> h(n, -1), e(m), ne(m);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    for (int i = 1; i < n; i++) add(i - 1, i);
    vector<int> f(n);
    iota(f.begin(), f.end(), 0);

    vector<int> res;
    res.reserve(qs.size());
    auto dfs = [&](this auto &&dfs, int u) -> void {
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (f[v] > f[u] + 1) {
          f[v] = f[u] + 1;
          dfs(v);
        }
      }
    };
    for (auto &q : qs) {
      int u = q[0], v = q[1];
      add(u, v);
      dfs(u);
      res.push_back(f[n - 1]);
    }

    return res;
  }
};
// @lc code=end
