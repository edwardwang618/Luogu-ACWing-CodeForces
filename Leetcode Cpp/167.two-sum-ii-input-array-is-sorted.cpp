/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& a, int t) {
    for (int i = 0, j = a.size() - 1; i < j; ) {
      if (a[i] + a[j] < t) i++;
      else if (a[i] + a[j] > t) j--;
      else return {i + 1, j + 1};
    }

    return {};
  }
};
// @lc code=end
