/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
 public:
  string countAndSay(int n) {
    string s = "1";
    for (int i = 0; i < n - 1; ++i) {
      string res;
      int len = s.size();
      for (int j = 0; j < len; ++j) {
        int k = j + 1;
        while (k < len && s[k] == s[j]) {
          ++k;
        }
        res += to_string(k - j) + s[j];
        j = k - 1;
      }
      s = res;
    }
    return s;
  }
};
// @lc code=end
