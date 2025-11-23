/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
 */

// @lc code=start
class Solution {
 public:
  using UL = unsigned long;
  int maxFreq(string s, int maxLetters, int m, int maxSize) {
    int n = s.size();
    UL pow = 1, P = 131;
    for (int i = 0; i < m; i++) pow = pow * P;
    unordered_map<UL, int> mp;
    int cnt[26], letters = 0;
    memset(cnt, 0, sizeof cnt);
    int res = 0;
    UL ha = 0;
    for (int i = 0; i < n; i++) {
      ha = ha * P + s[i];
      cnt[s[i] - 'a']++;
      if (cnt[s[i] - 'a'] == 1) letters++;
      if (i >= m) {
        ha -= s[i - m] * pow;
        cnt[s[i - m] - 'a']--;
        if (!cnt[s[i - m] - 'a']) letters--;
      }
      if (i >= m - 1 && letters <= maxLetters) res = max(res, ++mp[ha]);
    }

    return res;
  }
};
// @lc code=end
