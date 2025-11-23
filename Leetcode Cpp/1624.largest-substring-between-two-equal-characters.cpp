/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    unordered_map<char, int> mp;
    int res = -1;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (mp.count(ch)) res = max(res, i - mp[ch] - 1);
      else mp[ch] = i;
    }

    return res;
  }
};
// @lc code=end
