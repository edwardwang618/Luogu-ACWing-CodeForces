/*
 * @lc app=leetcode id=2484 lang=cpp
 *
 * [2484] Count Palindromic Subsequences
 */

// @lc code=start
class Solution {
public:
  int countPalindromes(string &s) {
    constexpr int MOD = 1e9 + 7;
    int n = s.size();
    int pre[n][10][10], suf[n][10][10];
    memset(pre, 0, sizeof pre);
    memset(suf, 0, sizeof suf);

    int cnt[10]{};
    for (int i = 0; i < n; i++) {
      if (i) memcpy(pre[i], pre[i - 1], sizeof pre[i]);
      int d = s[i] - '0';
      for (int a = 0; a < 10; a++)
        pre[i][a][d] = (pre[i][a][d] + cnt[a]) % MOD;
      cnt[d]++;
    }

    memset(cnt, 0, sizeof cnt);
    for (int i = n - 1; i >= 0; i--) {
      if (i < n - 1) memcpy(suf[i], suf[i + 1], sizeof suf[i]);
      int d = s[i] - '0';
      for (int a = 0; a < 10; a++)
        suf[i][d][a] = (suf[i][d][a] + cnt[a]) % MOD;
      cnt[d]++;
    }
    using ll = long long;
    ll res = 0;
    for (int i = 2; i < n - 2; i++)
      for (int a = 0; a < 10; a++)
        for (int b = 0; b < 10; b++)
          res = (res + (ll)pre[i - 1][a][b] * suf[i + 1][b][a]) % MOD;

    return (int)res;
  }
};
// @lc code=end
