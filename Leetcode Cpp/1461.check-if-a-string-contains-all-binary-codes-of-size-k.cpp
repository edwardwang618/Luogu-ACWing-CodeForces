/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    unordered_set<int> set;
    for (int i = 0, x = 0; i < s.size(); i++) {
      x = x << 1 | (s[i] - '0');
      if (i >= k) x &= ~(1 << k);
      if (i >= k - 1) set.insert(x);
      if (set.size() == 1 << k) return true;
    }

    return false;
  }
};
// @lc code=end
