/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& a, int x) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (a[mid] >= x)
        r = mid;
      else
        l = mid + 1;
    }
    return a[l] >= x ? l : a.size();
  }
};
// @lc code=end
