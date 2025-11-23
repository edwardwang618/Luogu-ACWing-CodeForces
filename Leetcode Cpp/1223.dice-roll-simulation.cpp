/*
 * @lc app=leetcode id=1223 lang=cpp
 *
 * [1223] Dice Roll Simulation
 */

// @lc code=start
class Solution {
 public:
  int dieSimulator(int n, vector<int>& v) {
    const int MOD = 1e9 + 7;
    int f[n + 1][6][16];
    memset(f, 0, sizeof f);
    for (int i = 0; i < 6; i++) f[1][i][1] = 1;
    for (int i = 1; i < n; i++)
      for (int x = 0; x < 6; x++)
        for (int k = 1; k <= v[x]; k++)
          for (int y = 0; y < 6; y++) {
            int len = 1;
            if (x == y) {
              len = k + 1;
              if (len > v[x]) continue;
            }
            f[i + 1][y][len] = (f[i + 1][y][len] + f[i][x][k]) % MOD;
          }

    int res = 0;
    for (int i = 0; i < 6; i++)
      for (int j = 1; j <= v[i]; j++) res = (res + f[n][i][j]) % MOD;
    return res;
  }
};
// @lc code=end
