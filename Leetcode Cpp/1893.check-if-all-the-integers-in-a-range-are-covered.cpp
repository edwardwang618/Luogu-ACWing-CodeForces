/*
 * @lc app=leetcode id=1893 lang=cpp
 *
 * [1893] Check if All the Integers in a Range Are Covered
 */

// @lc code=start
class Solution {
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    int diff[52] = {0};
    for (auto& a : ranges) {
      diff[a[0]]++;
      diff[a[1] + 1]--;
    }

    for (int i = 1; i <= 51; i++) {
      diff[i] += diff[i - 1];
      if (left <= i && i <= right && !diff[i]) return false;
    }

    return true;
  }
};
// @lc code=end
