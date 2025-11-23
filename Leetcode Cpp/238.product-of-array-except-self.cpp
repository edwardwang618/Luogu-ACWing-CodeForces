/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& a) {
    int n = a.size();
    vector<int> res(n);
    res[0] = a[0];
    for (int i = 1; i < n; i++) res[i] = res[i - 1] * a[i];
    int r = 1;
    for (int i = n - 1; i > 0; i--) res[i] = res[i - 1] * r, r *= a[i];
    res[0] = r;
    return res;
  }
};
// @lc code=end
