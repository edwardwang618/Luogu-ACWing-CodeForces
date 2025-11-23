/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution {
 public:
  int hIndex(vector<int>& cs) {
    int n = cs.size();
    int l = 0, r = n;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (cs[n - mid] >= mid)
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }
};
// @lc code=end
