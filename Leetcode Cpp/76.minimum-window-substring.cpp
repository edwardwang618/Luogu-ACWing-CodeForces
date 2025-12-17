/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
  string minWindow(string &s, string &t) {
    int cnt[128] = {0};
    int c = 0;
    for (char ch : t)
      if (++cnt[ch] == 1)
        c++;

    int l = -1, r;
    for (int i = 0, j = 0; i < s.size(); i++) {
      if (!--cnt[s[i]])
        c--;
      if (!c) {
        while (cnt[s[j]] < 0)
          cnt[s[j++]]++;
        if (!~l || i - j < r - l)
          l = j, r = i;
      }
    }

    return ~l ? s.substr(l, r - l + 1) : "";
  }
};
// @lc code=end
