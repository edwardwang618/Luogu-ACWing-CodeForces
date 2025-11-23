/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, int> mps, mpt;
    for (int i = 0; i < s.size(); i++) {
      if (mps[s[i]] != mpt[t[i]]) return false;
      mps[s[i]] = mpt[t[i]] = i + 1;
    }

    return true;
  }
};
// @lc code=end
