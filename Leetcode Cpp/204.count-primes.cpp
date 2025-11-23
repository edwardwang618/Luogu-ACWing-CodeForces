/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
 public:
  int countPrimes(int n) {
    if (!n) return 0;
    bool st[n];
    memset(st, 0, sizeof st);
    int p[n], idx = 0;
    for (int i = 2; i < n; i++) {
      if (!st[i]) p[idx++] = i;
      for (int j = 0; p[j] * i < n; j++) {
        st[p[j] * i] = true;
        if (i % p[j] == 0) break;
      }
    }

    return idx;
  }
};
// @lc code=end
