/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
 public:
  // int countSubstrings(string s) {
  //   int n = s.size(), res = 0;
  //   bool f[n][n];
  //   memset(f, 0, sizeof f);
  //   for (int len = 1; len <= n; len++)
  //     for (int l = 0; l + len - 1 < n; l++) {
  //       int r = l + len - 1;
  //       if (len == 1) f[l][r] = true;
  //       else if (len == 2) f[l][r] = s[l] == s[r];
  //       else f[l][r] = s[l] == s[r] && f[l + 1][r - 1];

  //       if (f[l][r]) res++;
  //     }
  //   return res;
  // }

  int countSubstrings(string t) {
    int n = t.size();
    string s = "$#";
    for (int i = 0; i < n; i++) {
      s += t[i];
      s += '#';
    }
    s += '^';

    vector<int> p(s.size(), 0);
    int res = 0, mr = 0, mid = 0;
    for (int i = 1; i < s.size() - 1; i++) {
      if (i < mr)
        p[i] = min(p[2 * mid - i], mr - i);
      else
        p[i] = 1;

      while (s[i - p[i]] == s[i + p[i]]) p[i]++;

      if (i + p[i] > mr) {
        mr = i + p[i];
        mid = i;
      }

      res += p[i] / 2;
    }

    return res;
  }
};
// @lc code=end
