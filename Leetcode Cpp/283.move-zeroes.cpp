/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
  void moveZeroes(vector<int> &a) {
    int n = a.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (a[i]) a[j++] = a[i];
    }
    while (j < n) a[j++] = 0;
  }
};
// @lc code=end
