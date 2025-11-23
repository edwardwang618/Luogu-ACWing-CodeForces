/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */

// @lc code=start
class Solution {
 public:
  string decodeAtIndex(string s, int k) {
    long n = 0;
    for (char ch : s) 
      if (isdigit(ch)) n *= ch - '0';
      else n++;
    
    for (int i = s.size() - 1; i >= 0; i--) {
      char ch = s[i];
      if (isdigit(ch)) {
        int x = ch - '0';
        n /= x;
        k %= n;
        if (!k) k = n;
      } else {
        if (n == k) return string(1, ch);
        n--;
      }
    }

    return "";
  }
};
// @lc code=end
