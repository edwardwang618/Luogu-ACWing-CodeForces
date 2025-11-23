/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
class Solution {
 public:
  int minDifference(vector<int>& a) {
    int n = a.size();
    if (n <= 4) return 0;
    sort(a.begin(), a.end());
    int res = 2e9;
    for (int i = 0; i <= 3; i++) res = min(res, a[n - 4 + i] - a[i]);
    return res;
  }
};
// @lc code=end
