/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
 public:
  int strStr(string s, string p) {
    int n = s.size(), m = p.size();
    s = " " + s;
    p = " " + p;

    vector<int> ne(m + 1);
    for (int i = 2, j = 0; i <= m; i++) {
      while (j && p[i] != p[j + 1]) j = ne[j];
      if (p[i] == p[j + 1]) j++;
      ne[i] = j;
    }

    for (int i = 1, j = 0; i <= n; i++) {
      while (j && s[i] != p[j + 1]) j = ne[j];
      if (s[i] == p[j + 1]) j++;
      if (j == m) return i - m;
    }

    return -1;
  }
};
// @lc code=end

