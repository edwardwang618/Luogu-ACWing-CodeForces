/*
 * @lc app=leetcode id=1118 lang=cpp
 *
 * [1118] Number of Days in a Month
 */

// @lc code=start
class Solution {
 public:
  int numberOfDays(int year, int month) {
    static unordered_map<int, int> mp{{1, 31},  {3, 31},  {4, 30}, {5, 31},
                                      {6, 30},  {7, 31},  {8, 31}, {9, 30},
                                      {10, 31}, {11, 30}, {12, 31}};
    if (month != 2) return mp[month];
    return 28 + (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
  }
};
// @lc code=end
