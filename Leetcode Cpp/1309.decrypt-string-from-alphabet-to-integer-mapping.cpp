/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */

// @lc code=start
class Solution {
 public:
  string freqAlphabets(string s) {
    string res;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '#') {
        int t = s[i - 1] - '0' + 10 * (s[i - 2] - '0');
        res += 'a' + t - 1;
        i -= 2;
      } else if (s[i] == '0') {
        int t = 10 * (s[i - 1] - '0');
        res += 'a' + t - 1;
        i--;
      } else
        res += 'a' + s[i] - '0' - 1;
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
