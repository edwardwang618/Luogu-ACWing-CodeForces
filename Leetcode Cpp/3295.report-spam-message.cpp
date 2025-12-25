/*
 * @lc app=leetcode id=3295 lang=cpp
 *
 * [3295] Report Spam Message
 */

// @lc code=start
class Solution {
public:
  bool reportSpam(vector<string> &v, vector<string> &ban) {
    unordered_set<string> st(ban.begin(), ban.end());
    int cnt = 0;
    for (auto &s : v)
      if (st.count(s) && ++cnt >= 2)
        return true;
    return false;
  }
};
// @lc code=end
