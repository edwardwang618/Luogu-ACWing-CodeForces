/*
 * @lc app=leetcode id=1513 lang=cpp
 *
 * [1513] Number of Substrings With Only 1s
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  int numSub(string s) {
    constexpr int MOD = 1e9 + 7;
    ll res = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        int j = i;
        while (j < s.size() && s[j] == '1') j++;
        res = (res + (ll)(j - i) * (j - i + 1) / 2) % MOD;
        i = j;
      }
    }
    return (int)res;
  }
};
// @lc code=end
