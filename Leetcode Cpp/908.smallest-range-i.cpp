/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
class Solution {
 public:
  int smallestRangeI(vector<int>& a, int k) {
    if (a.size() == 1) return 0;
    int m = 2e9, M = -2e9;
    for (int x : a) m = min(m, x), M = max(M, x);
    m += k;
    M -= k;
    return max(0, M - m);
  }
};
// @lc code=end
