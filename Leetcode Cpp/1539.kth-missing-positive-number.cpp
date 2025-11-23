/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
 public:
  int findKthPositive(vector<int>& a, int k) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
      int m = l + (r - l + 1 >> 1);
      if (a[m] - (m + 1) < k)
        l = m;
      else
        r = m - 1;
    }

    return a[l] - (l + 1) >= k ? k : k + l + 1;
  }
};
// @lc code=end
