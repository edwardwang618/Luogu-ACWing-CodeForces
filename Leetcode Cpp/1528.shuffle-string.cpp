/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
class Solution {
 public:
  string restoreString(string s, vector<int>& ids) {
    for (int i = 0; i < s.size(); i++)
      while (ids[i] != i) {
        swap(s[i], s[ids[i]]);
        swap(ids[i], ids[ids[i]]);
      }
    return s;
  }
};
// @lc code=end
