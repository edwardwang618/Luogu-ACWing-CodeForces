/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int res = 0, n = customers.size();
    for (int i = 0, s = 0; i < n; i++) {
      s += grumpy[i] * customers[i];
      if (i >= minutes) s -= grumpy[i - minutes] * customers[i - minutes];
      res = max(res, s);
    }

    for (int i = 0; i < n; i++) res += !grumpy[i] * customers[i];

    return res;
  }
};
// @lc code=end
