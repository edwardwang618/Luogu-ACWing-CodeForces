/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
 public:
  int findPeakElement(vector<int>& a) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (a[mid] > a[mid + 1]) r = mid;
      else l = mid + 1;
    }

    return l;
  }
};
// @lc code=end
