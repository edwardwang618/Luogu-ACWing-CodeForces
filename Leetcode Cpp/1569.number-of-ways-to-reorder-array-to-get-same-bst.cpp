/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  int numOfWays(vector<int> &a) {
    int n = a.size();
    vector C(n + 1, vector<ll>(n + 1, 0));
    static constexpr int MOD = 1e9 + 7;
    for (int i = 0; i <= n; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++)
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }

    auto dfs = [&](this auto &&dfs, auto &a) -> ll {
      int n = a.size();
      if (n <= 1)
        return 1;
      int root = a[0];
      vector<int> l, r;
      l.reserve(n);
      r.reserve(n);
      for (int i = 1; i < n; i++)
        (a[i] < root ? l : r).push_back(a[i]);
      return C[a.size() - 1][l.size()] * dfs(l) % MOD * dfs(r) % MOD;
    };

    return (dfs(a) - 1 + MOD) % MOD;
  }
};
// @lc code=end
