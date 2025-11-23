/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& a) {
    int j = 0;
    for (int i = 0; i < a.size(); i++)
      if (a[i]) a[j++] = a[i];
    while (j < a.size()) a[j++] = 0;
  }
};
// @lc code=end
