/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
 public:
  string addBinary(string a, string b) {
    string s;
    int t = 0;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0;) {
      if (i >= 0) t += a[i--] - '0';
      if (j >= 0) t += b[j--] - '0';
      s += to_string(t % 2);
      t >>= 1;
    }

    if (t) s += '1';
    reverse(s.begin(), s.end());
    return s;
  }
};
// @lc code=end
