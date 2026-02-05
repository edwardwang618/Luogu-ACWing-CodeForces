/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
public:
  int maxScore(string &s) {
    int cnt1 = 0;
    for (char ch : s) if (ch == '1') cnt1++;
    int res = 0, cnt0 = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0') cnt0++;
      else cnt1--;
      res = max(res, cnt0 + cnt1);
    }
    return res;
  }
};
// @lc code=end
