/*
 * @lc app=leetcode id=1566 lang=cpp
 *
 * [1566] Detect Pattern of Length M Repeated K or More Times
 */

// @lc code=start
class Solution {
 public:
  bool containsPattern(vector<int>& a, int m, int k) {
    int cnt = 0;
    for (int i = 0; i + m < a.size(); i++) {
      if (a[i] == a[i + m]) {
        if (++cnt == (k - 1) * m) return true;
      } else
        cnt = 0;
    }
    return false;
  }
};
// @lc code=end
