/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
 public:
  int findMin(vector<int>& a) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (a[mid] < a[0]) r = mid;
      else l = mid + 1;
    }

    return a[l] < a[0] ? a[l] : a[0];
  }
};
// @lc code=end
