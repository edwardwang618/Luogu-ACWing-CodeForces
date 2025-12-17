/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
  bool search(vector<int> &a, int t) {
    return find(a.begin(), a.end(), t) != a.end();
  }
};
// @lc code=end
