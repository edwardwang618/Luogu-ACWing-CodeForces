/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& a) {
    int n = a.size();
    int l = 0, r = 0, far = 0;
    while (l <= r) {
      for (int i = l; i <= r; i++) {
        far = max(far, i + a[i]);
        if (far >= n - 1) return true;
      }
      l = r + 1;
      r = far;
    }
    return false;
  }
};
// @lc code=end
