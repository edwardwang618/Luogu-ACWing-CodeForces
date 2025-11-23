/*
 * @lc app=leetcode id=1360 lang=cpp
 *
 * [1360] Number of Days Between Two Dates
 */

// @lc code=start
class Solution {
 public:
  int daysBetweenDates(string date1, string date2) {
    return abs(calc(date1) - calc(date2));
  }

#define is_leap(x) (x % 100 && x % 4 == 0 || x % 400 == 0)

  int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int calc(string date) {
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    int res = 0;
    for (int i = 1971; i < year; i++) res += 365 + is_leap(i);
    for (int i = 1; i < month; i++) {
      res += days[i];
      if (i == 2) res += is_leap(year);
    }

    return res + day;
  }
};
// @lc code=end
