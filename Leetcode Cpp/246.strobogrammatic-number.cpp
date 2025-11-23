/*
 * @lc app=leetcode id=246 lang=cpp
 *
 * [246] Strobogrammatic Number
 */

// @lc code=start
class Solution {
 public:
  bool isStrobogrammatic(string s) {
    unordered_map<char, char> mp = {
        {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

    for (int i = 0; j = s.size() - 1; i <= j; i++, j--) {
      char l = s[i], r = s[j];
      if (!mp.count(l)) return false;
      if (i != j) {
        if (mp[l] != r) return false;
      } else {
        if (mp[l] != l) return false;
      }
    }
    return true;
  }
};
// @lc code=end