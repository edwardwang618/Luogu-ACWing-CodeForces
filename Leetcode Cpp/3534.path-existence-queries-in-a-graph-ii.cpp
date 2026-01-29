/*
 * @lc app=leetcode id=3534 lang=cpp
 *
 * [3534] Path Existence Queries in a Graph II
 */

// @lc code=start
class Solution {
public:
  vector<int> pathExistenceQueries(int n, vector<int> &a, int maxDiff,
                                   vector<vector<int>> &qs) {
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<int> pos(n);
    for (int i = 0; i < n; i++)
      pos[idx[i]] = i;

    const int LOG = n == 1 ? 1 : bit_width(unsigned(n - 1));
    vector f(LOG, vector<int>(n));
    for (int i = 0, j = 0; i < n; i++) {
      while (j < n && a[idx[j]] - a[idx[i]] <= maxDiff)
        j++;
      f[0][i] = j - 1;
    }
    for (int k = 1; k < LOG; k++)
      for (int i = 0; i < n; i++)
        f[k][i] = f[k - 1][f[k - 1][i]];

    vector<int> res;
    res.reserve(qs.size());
    for (auto &q : qs) {
      int u = pos[q[0]], v = pos[q[1]];
      if (u > v)
        swap(u, v);
      int step = 0;
      for (int k = LOG - 1; k >= 0; k--)
        if (f[k][u] < v)
          u = f[k][u], step += 1 << k;
      res.push_back(f[0][u] < v ? -1 : step + (u < v));
    }
    return res;
  }
};
// @lc code=end
