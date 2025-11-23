/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
 public:
  int removeElement(vector<int>& a, int x) {
    int i = 0;
    for (int j = 0; j < a.size(); j++)
      if (a[j] != x) a[i++] = a[j];
    return i;
  }
};
// @lc code=end
