/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
 public:
  string multiply(string x, string y) {
    if (x == "0" || y == "0") return "0";
    int m = x.size(), n = y.size();
    vector<int> res(m + n);
    for (int i = m - 1; i >= 0; i--)
      for (int j = n - 1; j >= 0; j--)
        res[m + n - 2 - (i + j)] += (x[i] - '0') * (y[j] - '0');
    for (int i = 0; i < m + n - 1; i++) {
      res[i + 1] += res[i] / 10;
      res[i] %= 10;
    }
    while (!res.back()) res.pop_back();
    string s;
    s.reserve(res.size());
    for (int x : res) s += '0' + x;
    reverse(s.begin(), s.end());
    return s;
  }
};
// @lc code=end
