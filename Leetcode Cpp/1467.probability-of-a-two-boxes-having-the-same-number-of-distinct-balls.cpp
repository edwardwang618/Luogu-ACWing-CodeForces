/*
 * @lc app=leetcode id=1467 lang=cpp
 *
 * [1467] Probability of a Two Boxes Having The Same Number of Distinct Balls
 */

// @lc code=start
class Solution {
public:
  double getProbability(vector<int> &bs) {
    using ll = long long;
    int k = bs.size();
    int n = accumulate(bs.begin(), bs.end(), 0) / 2;

    static constexpr int M = 6;
    static constexpr auto C = [] {
      array<array<ll, M + 1>, M + 1> C{};
      C[0][0] = 1;
      for (int i = 1; i <= M; i++)
        for (int j = 0; j <= i; j++) {
          C[i][j] = C[i - 1][j];
          if (j) C[i][j] += C[i - 1][j - 1];
        }
      return C;
    }();

    vector f(k, vector(n + 1, vector<ll>(2 * k + 1, -1)));
    auto dfs = [&](this auto &&dfs, int i, int j, int diff) -> ll {
      if (i == k) return (!j && diff == k) ? 1 : 0;
      if (~f[i][j][diff]) return f[i][j][diff];
      ll res = 0;
      for (int x = 0; x <= min(j, bs[i]); x++) {
        int ndiff = x == bs[i] ? diff + 1 : (!x ? diff - 1 : diff);
        res += dfs(i + 1, j - x, ndiff) * C[bs[i]][x];
      }
      return f[i][j][diff] = res;
    };

    // C(2n, n)
    ll total = 1;
    for (int i = 0; i < n; i++)
      total = total * (2 * n - i) / (i + 1);

    return (double)dfs(0, n, k) / total;
  }
};
// @lc code=end
