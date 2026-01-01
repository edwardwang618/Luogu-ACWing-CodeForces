/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
class Solution {
public:
  int minCut(string &s) {
    int n = s.size();
    vector<int> f(n + 1);
    iota(f.begin(), f.end(), -1);
    for (int mid = 0; mid < n; mid++) {
      for (int i = mid, j = mid; i >= 0 && j < n && s[i] == s[j]; i--, j++)
        f[j + 1] = min(f[j + 1], f[i] + 1);

      for (int i = mid, j = mid + 1; i >= 0 && j < n && s[i] == s[j]; i--, j++)
        f[j + 1] = min(f[j + 1], f[i] + 1);
    }

    return f[n];
  }
};
// @lc code=end
