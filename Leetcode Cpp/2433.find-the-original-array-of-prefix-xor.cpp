/*
 * @lc app=leetcode id=2433 lang=cpp
 *
 * [2433] Find The Original Array of Prefix Xor
 */

// @lc code=start
class Solution {
 public:
  vector<int> findArray(vector<int>& a) {
    for (int i = a.size() - 1; i > 0; i--) a[i] ^= a[i - 1];
    return a;
  }
};
// @lc code=end
