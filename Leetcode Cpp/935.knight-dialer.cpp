/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
class Solution {
 public:
  int knightDialer(int n) {
    vector<int> v[10] = {
      {4, 6},
      {6, 8}, 
      {7, 9},
      {4, 8},
      {3, 9, 0},
      {},
      {1, 7, 0},
      {2, 6},
      {1, 3},
      {2, 4}};
    int MOD = 1e9 + 7;
    int f[2][10];
    memset(f, 0, sizeof f);
    fill(begin(f[0]), end(f[0]), 1);
    for (int i = 0; i < n - 1; i++) {
      fill(begin(f[i + 1 & 1]), end(f[i + 1 & 1]), 0);
      for (int k = 0; k <= 9; k++)
        for (int x : v[k])
          f[i + 1 & 1][x] = (f[i + 1 & 1][x] + f[i & 1][k]) % MOD;
    }

    int res = 0;
    for (int i = 0; i <= 9; i++)
      res = (res + f[n - 1 & 1][i]) % MOD;
    return res;
  }
};
// @lc code=end
