/*
 * @lc app=leetcode id=828 lang=cpp
 *
 * [828] Count Unique Characters of All Substrings of a Given String
 */

// @lc code=start
class Solution {
 public:
  int uniqueLetterString(string s) {
    int cur[26], pre[26];
    memset(cur, -1, sizeof cur);
    memset(pre, -1, sizeof pre);

    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      int idx = s[i] - 'A';
      res += (i - cur[idx]) * (cur[idx] - pre[idx]);
      pre[idx] = cur[idx];
      cur[idx] = i;
    }

    for (int i = 0; i < 26; i++) res += (s.size() - cur[i]) * (cur[i] - pre[i]);
    return res;
  }
};
// @lc code=end
