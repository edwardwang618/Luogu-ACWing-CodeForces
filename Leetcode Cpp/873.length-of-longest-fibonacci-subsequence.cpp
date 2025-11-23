/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& a) {
    int res = 0, n = a.size();
    int f[n][n];
    memset(f, 0, sizeof f);
    unordered_map<int, int> mp;
    for (int i = 0; i + 1 < n; i++) {
      for (int j = i + 1; j < n; j++) {
        f[i][j] = 2;
        int x = a[j] - a[i];
        if (x < a[i] && mp.count(x)) f[i][j] = 1 + f[mp[x]][i];
        res = max(res, f[i][j]);
      }
      mp[a[i]] = i;
    }

    return res == 2 ? 0 : res;
  }
};
// @lc code=end
