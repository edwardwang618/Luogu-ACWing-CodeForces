/*
 * @lc app=leetcode id=266 lang=cpp
 *
 * [266] Palindrome Permutation
 */

// @lc code=start
class Solution {
 public:
  bool canPermutePalindrome(string s) {
    unordered_map<char, int> mp;
    for (char ch : s) mp[ch]++;
    bool has_odd = false;
    for (auto &[k, v] : mp)
      if (v % 2) {
        if (has_odd)
          return false;
        else
          has_odd = true;
      }

    return true;
  }
};
// @lc code=end
