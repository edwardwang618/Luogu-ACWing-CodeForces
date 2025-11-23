/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    int a = 0, cnt = 0;
    for (char ch : allowed) a |= 1 << ch - 'a';
    for (auto& s : words)
      for (char ch : s)
        if (!(a >> ch - 'a' & 1)) {
          cnt++;
          break;
        }
    return words.size() - cnt;
  }
};
// @lc code=end
