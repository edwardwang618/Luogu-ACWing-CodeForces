/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
 public:
  int longestArithSeqLength(vector<int>& a) {
    int n = a.size(), f[n][n];
    memset(f, 0, sizeof f);
    unordered_map<int, int> mp;
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        f[i][j] = 2;
        int t = 2 * a[i] - a[j];
        if (mp.count(t)) f[i][j] = f[mp[t]][i] + 1;
        res = max(res, f[i][j]);
      }
      mp[a[i]] = i;
    }

    return res;
  }
};
// @lc code=end
