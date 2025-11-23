/*
 * @lc app=leetcode id=1625 lang=cpp
 *
 * [1625] Lexicographically Smallest String After Applying Operations
 */

// @lc code=start
class Solution {
 public:
  string findLexSmallestString(string s, int a, int b) {
    int n = s.size();
    string res = s;
    static auto f = [](char& ch, int x) { ch = '0' + (ch - '0' + x) % 10; };
    if (b % 2 == 0) {
      for (int i = 0; i < 10; i++) {
        for (int k = 1; k < n; k += 2) f(s[k], a);
        auto t = s;
        for (int k = 0; k < n; k++) {
          t = t.substr(n - b) + t.substr(0, n - b);
          if (t < res) res = t;
        }
      }
    } else {
      for (int i = 0; i < 10; i++) {
        for (int k = 1; k < n; k += 2) f(s[k], a);
        for (int j = 0; j < 10; j++) {
          for (int k = 0; k < n; k += 2) f(s[k], a);
          auto t = s;
          for (int k = 0; k < n; k++) {
            t = t.substr(n - b) + t.substr(0, n - b);
            if (t < res) res = t;
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
