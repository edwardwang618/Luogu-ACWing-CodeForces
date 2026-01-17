/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 */

// @lc code=start
class Solution {
public:
  string shiftingLetters(string &s, vector<int> &shifts) {
    string res;
    for (int i = s.size() - 1, sum = 0; i >= 0; i--) {
      sum = (sum + shifts[i]) % 26;
      res += (s[i] - 'a' + sum) % 26 + 'a';
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
