/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
class Solution {
 public:
  vector<string> n0_19 = {"Zero",    "One",       "Two",      "Three",
                          "Four",    "Five",      "Six",      "Seven",
                          "Eight",   "Nine",      "Ten",      "Eleven",
                          "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                          "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

  vector<string> n20_90 = {"Twenty", "Thirty",  "Forty",  "Fifty",
                           "Sixty",  "Seventy", "Eighty", "Ninety"};

  vector<string> n1000 = {" Billion ", " Million ", " Thousand ", ""};

  string numberToWords(int num) {
    if (num == 0) return "Zero";
    string res;
    for (int i = 1e9, j = 0; i >= 1; i /= 1000, j++)
      if (num >= i) {
        res += get(num / i) + n1000[j];
        num %= i;
      }

    if (res.back() == ' ') res.pop_back();
    return res;
  }

  string get(int x) {
    string res;
    if (x >= 100) {
      res += n0_19[x / 100] + " Hundred ";
      x %= 100;
    }
    if (x >= 20) {
      res += n20_90[x / 10 - 2] + ' ';
      x %= 10;
      if (x != 0) res += n0_19[x];
    } else if (x > 0)
      res += n0_19[x];

    if (res.back() == ' ') res.pop_back();
    return res;
  }
};
// @lc code=end
