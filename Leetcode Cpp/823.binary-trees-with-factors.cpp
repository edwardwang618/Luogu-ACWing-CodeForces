/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& a) {
    const int MOD = 1e9 + 7;
    sort(a.begin(), a.end());
    int n = a.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]] = i;
    long f[n];
    memset(f, 0, sizeof f);
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
      f[i] = 1;
      for (int j = 0; j < i; j++)
        if (a[i] % a[j] == 0) {
          int k = a[i] / a[j];
          if (mp.count(k)) f[i] = (f[i] + f[j] * f[mp[k]]) % MOD;
        }
      res = (res + f[i]) % MOD;
    }

    return res;
  }
};
// @lc code=end
