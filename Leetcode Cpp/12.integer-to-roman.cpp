/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
 public:
  string intToRoman(int num) {
    string rome[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                     "XL", "X",  "IX", "V",  "IV", "I"};
    int number[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string s;
    for (int i = 0; i < 13; i++) {
      while (num >= number[i]) {
        s += rome[i];
        num -= number[i];
      }
    }

    return s;
  }
};
// @lc code=end
