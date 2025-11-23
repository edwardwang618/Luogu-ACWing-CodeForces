/*
 * @lc app=leetcode id=2318 lang=cpp
 *
 * [2318] Number of Distinct Roll Sequences
 */

// @lc code=start
class Solution {
 public:
  int distinctSequences(int n) {
    const int MOD = 1e9 + 7;
    function<int(int, int)> gcd = [&](int x, int y) {
      return y ? gcd(y, x % y) : x;
    };
    int f[10001][7][7] = {0};
    if (n == 1) return 6;
    for (int i = 1; i <= 6; i++)
      for (int j = 1; j <= 6; j++) {
        f[1][i][j] = 6;
        if (gcd(i, j) == 1 && i != j) f[2][i][j] = 1;
      }
    for (int k = 3; k <= n; k++)
      for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
          if (f[2][i][j])
            for (int u = 1; u <= 6; u++)
              if (u != i && f[2][u][j])
                f[k][i][j] = (f[k][i][j] + f[k - 1][j][u]) % MOD;

    int res = 0;
    for (int i = 1; i <= 6; i++)
      for (int j = 1; j <= 6; j++) res = (res + f[n][i][j]) % MOD;
    return res;
  }
};
// @lc code=end
