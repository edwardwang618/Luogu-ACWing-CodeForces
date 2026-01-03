/*
 * @lc app=leetcode id=3615 lang=cpp
 *
 * [3615] Longest Palindromic Path in Graph
 */

// @lc code=start
class Solution {
public:
  int maxLen(int n, vector<vector<int>> &es, string &s) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    
    vector<bool> used((1 << n) * n * n);
    auto id = [&](int mask, int i, int j) {
      return mask * n * n + i * n + j;
    };
    using TIII = tuple<int, int, int>;
    vector<vector<TIII>> f(n + 1);
    int res = 1;
    for (int i = 0; i < n; i++) {
      int mask = 1 << i;
      used[id(mask, i, i)] = true;
      f[1].emplace_back(mask, i, i);
    }

    for (auto &e : es) {
      int u = e[0], v = e[1];
      add(u, v), add(v, u);
      if (s[u] == s[v]) {
        int mask = (1 << u) | (1 << v);
        used[id(mask, u, v)] = used[id(mask, v, u)] = true;
        f[2].emplace_back(mask, u, v);
        res = 2;
      }
    }

    for (int sz = 1; sz <= n - 2; sz++)
      for (auto [mask, i, j] : f[sz])
        for (int ii = h[i]; ~ii; ii = ne[ii]) {
          int u = e[ii];
          if (mask >> u & 1) continue;
          for (int jj = h[j]; ~jj; jj = ne[jj]) {
            int v = e[jj];
            if (mask >> v & 1) continue;
            if (u == v) continue;
            if (s[u] != s[v]) continue;
            int nmask = mask | (1 << u) | (1 << v);
            int iduv = id(nmask, u, v), idvu = id(nmask, v, u);
            if (!used[iduv] && !used[idvu]) {
              used[iduv] = used[idvu] = true;
              f[sz + 2].emplace_back(nmask, u, v);
              res = max(res, sz + 2);
            }
          }
        }

    return res;
  }
};
// @lc code=end
