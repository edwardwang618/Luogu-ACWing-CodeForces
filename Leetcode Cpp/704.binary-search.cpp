/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& a, int t) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (a[mid] >= t) r = mid;
      else l = mid + 1;
    }

    return a[l] == t ? l : -1;
  }
};
// @lc code=end
