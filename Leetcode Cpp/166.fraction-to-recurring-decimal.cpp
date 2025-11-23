/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
 public:
  string fractionToDecimal(int a, int b) {
    long x = a, y = b;
    string s;
    if (x % y == 0) return to_string(x / y);
    if ((x < 0) ^ (y < 0)) s = "-";
    x = abs(x), y = abs(y);
    s += to_string(x / y) + ".";
    unordered_map<int, int> mp;
    x %= y;
    while (x && !mp.count(x)) {
      mp[x] = s.size();
      x *= 10;
      s += to_string(x / y);
      x %= y;
    }

    if (!x) return s;
    return s.substr(0, mp[x]) + '(' + s.substr(mp[x]) + ')';
  }
};
// @lc code=end
