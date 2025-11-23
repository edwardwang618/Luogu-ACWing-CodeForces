/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

// @lc code=start
class Solution {
 public:
  int findSpecialInteger(vector<int>& a) {
    int n = a.size(), c = n / 4;
    for (int i = c; i < n; i += c) {
      int x = a[i];
      int l = lower_bound(a.begin(), a.end(), x) - a.begin();
      int r = upper_bound(a.begin(), a.end(), x) - a.begin();
      if (r - l > c) return x;
    }
    return -1;
  }
};
// @lc code=end
