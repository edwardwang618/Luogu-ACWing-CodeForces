/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
 public:
  bool isAlienSorted(vector<string>& ws, string ord) {
    unordered_map<char, int> mp;
    for (int i = 0; i < ord.size(); i++) mp[ord[i]] = i;
    auto f = [&](string& s, string& t) {
      for (int i = 0; i < s.size() && i < t.size(); i++)
        if (s[i] != t[i]) return mp[s[i]] < mp[t[i]];
      return s.size() <= t.size();
    };
    for (int i = 0; i + 1 < ws.size(); i++)
      if (!f(ws[i], ws[i + 1])) return false;
    return true;
  }
};
// @lc code=end
