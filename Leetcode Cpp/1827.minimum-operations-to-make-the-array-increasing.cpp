/*
 * @lc app=leetcode id=1827 lang=cpp
 *
 * [1827] Minimum Operations to Make the Array Increasing
 */

// @lc code=start
class Solution {
 public:
  int minOperations(vector<int>& a) {
    int res = 0;
    for (int i = 1; i < a.size(); i++)
      if (a[i] <= a[i - 1]) {
        res += a[i - 1] + 1 - a[i];
        a[i] += a[i - 1] + 1 - a[i];
      }
    
    return res;
  }
};
// @lc code=end
