/*
 * @lc app=leetcode id=2247 lang=cpp
 *
 * [2247] Maximum Cost of Trip With K Highways
 */

// @lc code=start
class Solution {
public:
  int maximumCost(int n, vector<vector<int>> &es, int k) {
    if (k + 1 > n) return -1;
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
    vector<vector<int>> f(1 << n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) f[1 << i][i] = 0;
    for (int i = 1; i < (1 << n); i++) {
      if (popcount(unsigned(i)) >= k + 1) continue;
      for (int u = 0; u < n; u++)
        if (~f[i][u] && i >> u & 1)
          for (int j = h[u]; ~j; j = ne[j]) {
            int v = e[j], c = w[j];
            if (!(i >> v & 1)) {
              int ni = i ^ (1 << v);
              f[ni][v] = max(f[ni][v], f[i][u] + c);
            }
          }
    }

    int res = -1;
    for (int i = 1; i < (1 << n); i++)
      if (popcount(unsigned(i)) == k + 1)
        for (int u = 0; u < n; u++)
          res = max(res, f[i][u]);
    return res;
  }
};
// @lc code=end
