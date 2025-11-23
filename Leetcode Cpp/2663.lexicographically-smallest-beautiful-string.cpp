/*
 * @lc app=leetcode id=2663 lang=cpp
 *
 * [2663] Lexicographically Smallest Beautiful String
 */

// @lc code=start
class Solution {
 public:
  string smallestBeautifulString(string s, int k) {
    auto fail = [&](int i, char ch) {
      return (i >= 1 && ch == s[i - 1]) || (i >= 2 && ch == s[i - 2]);
    };

    for (int i = s.size() - 1; i >= 0; i--)
      for (char ch = s[i] + 1; ch <= 'a' + k - 1; ch++) {
        if (fail(i, ch)) continue;
        s[i] = ch;
        for (int j = i + 1; j < s.size(); j++) {
          for (char ch = 'a'; ch <= 'a' + k - 1; ch++) {
            if (fail(j, ch)) continue;
            s[j] = ch;
            break;
          }
        }
        return s;
      }
    return "";
  }
};
// @lc code=end
