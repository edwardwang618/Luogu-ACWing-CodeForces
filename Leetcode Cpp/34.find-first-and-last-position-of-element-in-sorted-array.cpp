/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> searchRange(vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;
    if (l > r) return {-1, -1};
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (a[mid] >= x)
        r = mid;
      else
        l = mid + 1;
    }

    if (a[l] != x) return {-1, -1};
    vector<int> res{l};
    r = (int)a.size() - 1;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (a[mid] <= x)
        l = mid;
      else
        r = mid - 1;
    }
    res.push_back(l);
    return res;
  }
};
// @lc code=end
