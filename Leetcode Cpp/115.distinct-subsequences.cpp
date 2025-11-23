/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  int numDistinct(string s, string t) {
    int n = s.size(), m = t.size();
    ll f[2][m];
    memset(f, 0, sizeof f);
    f[0][0] = s[0] == t[0];
    for (int i = 1; i < n; i++)
      for (int j = 0; j < m; j++) {
        f[i & 1][j] = f[i - 1 & 1][j];
        if (s[i] == t[j]) f[i & 1][j] += j ? f[i - 1 & 1][j - 1] : 1;
        f[i & 1][j] %= 1ll << 32;
      }
    return f[n - 1 & 1][m - 1];
  }
};
// @lc code=end
