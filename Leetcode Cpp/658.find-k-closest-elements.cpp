/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
 public:
  vector<int> findClosestElements(vector<int>& a, int k, int x) {
    vector<int> res;
    int l = 0, r = a.size() - k;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (x - a[mid] <= a[mid + k] - x) r = mid;
      else l = mid + 1;
    }

    return vector<int>(a.begin() + l, a.begin() + l + k);
  }
};
// @lc code=end
