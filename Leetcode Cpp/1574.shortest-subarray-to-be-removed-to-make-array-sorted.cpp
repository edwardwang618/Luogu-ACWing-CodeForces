/*
 * @lc app=leetcode id=1574 lang=cpp
 *
 * [1574] Shortest Subarray to be Removed to Make Array Sorted
 */

// @lc code=start
class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& a) {
    int n = a.size();
    int l = 0, r = n - 1;
    while (l + 1 < n && a[l + 1] >= a[l]) l++;
    if (l == n - 1) return 0;
    while (a[r - 1] <= a[r]) r--;
    int res = max(l + 1, n - r);
    for (int i = 0; i <= l; i++)
      if (a[i] <= a[r]) res = max(res, i + 1 + n - r);
      else {
        while (r < n && a[r] < a[i]) r++;
        if (r == n) break;
      }
    
    return n - res;
  }
};
// @lc code=end
