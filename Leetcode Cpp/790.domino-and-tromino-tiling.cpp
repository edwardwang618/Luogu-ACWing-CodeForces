/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
 public:
  int numTilings(int n) {
    const int MOD = 1e9 + 7;
    vector<vector<int>> f(n + 1, vector<int>(4));
    bool g[4][4] = {
      {1, 1, 1, 1},
      {0, 0, 1, 1},
      {0, 1, 0, 1},
      {1, 0, 0, 0}
    };
    f[0][0] = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++)
          if (g[j][k]) f[i + 1][k] = (f[i + 1][k] + f[i][j]) % MOD;
    return f[n][0];
  }
};
// @lc code=end
