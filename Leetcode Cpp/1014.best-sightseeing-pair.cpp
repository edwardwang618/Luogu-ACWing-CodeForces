/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int res = INT_MIN;
    for (int i = 0, sum = 0; i < values.size(); i++) {
      if (i) res = max(res, sum + values[i] - i);
      sum = max(sum, values[i] + i);
    }

    return res;
  }
};
// @lc code=end
