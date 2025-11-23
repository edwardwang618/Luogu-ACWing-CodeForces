/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& a, int x) {
    int n = a.size(), l = 0, r = n - 1;
    if (l > r) return -1;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (a[mid] == x) return mid;
      if (a[0] <= a[mid]) {
        if (a[0] <= x && x <= a[mid])
          r = mid;
        else
          l = mid + 1;
      } else {
        if (a[mid + 1] <= x && x <= a[n - 1])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }

    return a[l] == x ? l : -1;
  }
};
// @lc code=end
