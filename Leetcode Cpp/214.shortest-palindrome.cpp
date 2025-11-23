/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution {
 public:
  string shortestPalindrome(string t) {
    string s = ' ' + t + '$';
    reverse(t.begin(), t.end());
    s += t;

    int n = s.size() - 1;
    int ne[n + 1];
    fill(ne, ne + n + 1, 0);
    for (int i = 2, j = 0; i <= n; i++) {
      while (j && s[i] != s[j + 1]) j = ne[j];
      if (s[i] == s[j + 1]) j++;
      ne[i] = j;
    }

    int len = ne[n];
    string a = s.substr(1, len), b = s.substr(1 + len, n / 2 - len);
    return string(b.rbegin(), b.rend()) + a + b;
  }
};
// @lc code=end
