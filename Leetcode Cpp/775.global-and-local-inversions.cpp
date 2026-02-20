/*
 * @lc app=leetcode id=775 lang=cpp
 *
 * [775] Global and Local Inversions
 */

// @lc code=start
class Solution {
public:
  bool isIdealPermutation(vector<int> &a) {
    for (int i = 0; i < a.size(); i++)
      if (abs(a[i] - i) >= 2) return false;
    return true;
  }
};
// @lc code=end
