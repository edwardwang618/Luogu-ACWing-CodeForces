/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
 public:
  int myAtoi(string s) {
    int i = 0;
    int n = s.length();
    while (i < n && s[i] == ' ') i++;
    if (i == n) return 0;

    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
      sign = (s[i] == '+') ? 1 : -1;
      i++;
    }

    long res = 0;
    for (; i < n && isdigit(s[i]); i++) {
      res = res * 10 + (s[i] - '0');
      if (res > INT_MAX) return sign == 1 ? INT_MAX : INT_MIN;
    }

    return (int)(sign * res);
  }
};
// @lc code=end
