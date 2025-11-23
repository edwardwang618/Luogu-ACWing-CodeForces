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
    vector<int> res(x.size() + y.size());
    for (int i = x.size() - 1; i >= 0; i--)
      for (int j = y.size() - 1; j >= 0; j--)
        res[x.size() + y.size() - 2 - (i + j)] += (x[i] - '0') * (y[j] - '0');
    for (int i = 0; i < res.size() - 1; i++) {
      res[i + 1] += res[i] / 10;
      res[i] %= 10;
    }
    while (!res.back()) res.pop_back();
    string s;
    for (int x : res) s += '0' + x;
    reverse(s.begin(), s.end());
    return s;
  }
};
// @lc code=end
