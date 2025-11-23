/*
 * @lc app=leetcode id=1278 lang=cpp
 *
 * [1278] Palindrome Partitioning III
 */

// @lc code=start
class Solution {
 public:
  int palindromePartition(string s, int k) {
    int n = s.size();
    int cost[n][n];
    memset(cost, 0, sizeof cost);
    for (int len = 2; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        cost[l][r] = (s[l] == s[r] ? 0 : 1);
        if (len > 2) cost[l][r] += cost[l + 1][r - 1];
      }

    int f[n + 1][k + 1];
    memset(f, 0x3f, sizeof f);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      f[i][1] = cost[0][i - 1];
      for (int j = 2; j <= k; j++)
        for (int l = 1; l <= i; l++)
          f[i][j] = min(f[i][j], f[i - l][j - 1] + cost[i - l][i - 1]);
    }
    return f[n][k];
  }
};
// @lc code=end
