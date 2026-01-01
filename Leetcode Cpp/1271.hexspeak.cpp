/*
 * @lc app=leetcode id=1271 lang=cpp
 *
 * [1271] Hexspeak
 */

// @lc code=start
class Solution {
public:
  string toHexspeak(string &s) {
    auto to_char = [](int x) {
      if (x < 10) return '0' + x;
      return 'A' + x - 10;
    };
    auto div = [&](string &s) -> pair<string, int> {
      string quo;
      int rem = 0;
      for (char ch : s) {
        rem = rem * 10 + ch - '0';
        quo += to_char(rem / 16);
        rem %= 16;
      }
      int i = 0;
      while (i + 1 < quo.size() && quo[i] == '0') i++;
      return {quo.substr(i), rem};
    };

    string res;
    int r;
    do {
      tie(s, r) = div(s);
      if (!r) res += 'O';
      else if (r == 1) res += 'I';
      else if (2 <= r && r <= 9) return "ERROR";
      else res += to_char(r);
    } while (s != "0");
    if (res.empty()) res = "O";
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
