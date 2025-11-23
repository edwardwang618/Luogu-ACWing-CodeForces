/*
 * @lc app=leetcode id=294 lang=cpp
 *
 * [294] Flip Game II
 */

// @lc code=start
class Solution {
 public:
  bool canWin(string s) {
    unordered_map<string, bool> mp;
    return dfs(s, mp);
  }

  bool dfs(string& s, unordered_map<string, bool>& mp) {
    if (mp.count(s)) return mp[s];
    for (int i = 0; i < s.size() - 1; i++)
      if (s[i] == '+' && s[i + 1] == '+') {
        s[i] = s[i + 1] = '-';
        if (!dfs(s, mp)) {
          s[i] = s[i + 1] = '+';
          return mp[s] = true;
        }

        s[i] = s[i + 1] = '+';
      }

    return mp[s] = false;
  }
};
// @lc code=end
