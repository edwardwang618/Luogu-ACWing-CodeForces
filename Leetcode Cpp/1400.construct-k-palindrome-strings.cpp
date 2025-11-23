/*
 * @lc app=leetcode id=1400 lang=cpp
 *
 * [1400] Construct K Palindrome Strings
 */

// @lc code=start
class Solution {
 public:
  bool canConstruct(string s, int k) {
    int n = s.size();
    if (n < k) return false;
    unordered_map<char, int> mp;
    for (char ch : s) mp[ch]++;
    int cnt = 0;
    for (auto &[k, v] : mp)
      if (v & 1) cnt++;

    return cnt <= k;
  }
};
// @lc code=end
