/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
 public:
  int jump(vector<int>& a) {
    int n = a.size();
    if (n <= 1) return 0;
    int res = 0;
    int l = 0, r = 0, far = 0;
    while (l <= r) {
      res++;
      for (int i = l; i <= r; i++) {
        far = max(far, i + a[i]);
        if (far >= n - 1) return res;
      }
      l = r + 1;
      r = far;
    }
    return res;
  }
};
// @lc code=end
