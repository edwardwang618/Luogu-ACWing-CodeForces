/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
      return false;
    vector<int> f(1 << maxChoosableInteger, -1);
    return dfs(0, 0, f, maxChoosableInteger, desiredTotal);
  }

  bool dfs(int st, int sum, auto& f, int mC, int dT) {
    if (~f[st]) return f[st];
    for (int i = 1; i <= mC; i++)
      if (!(st >> i - 1 & 1)) {
        if (sum + i >= dT || !dfs(st | (1 << i - 1), sum + i, f, mC, dT))
          return f[st] = 1;
      }
    return f[st] = 0;
  }
};
// @lc code=end
