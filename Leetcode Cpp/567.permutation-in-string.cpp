/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
  bool checkInclusion(string &s1, string &s2) {
    int n = s2.size(), m = s1.size();
    if (n < m) return false;
    vector<int> cnt(26);
    int tot = 0;
    for (char ch : s1)
      if (!cnt[ch - 'a']++)
        tot++;

    vector<int> mp(26);
    for (int i = 0; i < n; i++) {
      int idx1 = s2[i] - 'a';
      if (++mp[idx1] == cnt[idx1])
        tot--;
      if (i >= m) {
        int idx2 = s2[i - m] - 'a';
        if (--mp[idx2] == cnt[idx2] - 1)
          tot++;
      }
      if (!tot)
        return true;
    }

    return false;
  }
};
// @lc code=end
