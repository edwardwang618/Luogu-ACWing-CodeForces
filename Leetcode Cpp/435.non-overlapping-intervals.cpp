/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& is) {
    sort(is.begin(), is.end(),
         [](const vector<int>& i1, const vector<int>& i2) {
           return less<int>()(i1[1], i2[1]);
         });
    int cnt = 0, cur_end = INT_MIN;
    for (auto& i : is)
      if (i[0] >= cur_end) {
        cur_end = i[1];
        cnt++;
      }

    return is.size() - cnt;
  }
};
// @lc code=end
