/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
public:
  string removeKdigits(string &s, int k) {
    string res;
    res.reserve(s.size());
    for (char ch : s) {
      while (k && res.size() && res.back() > ch) {
        res.pop_back();
        k--;
      }
      res += ch;
    }
    res.resize(res.size() - k);
    int idx = 0;
    while (idx < res.size() && res[idx] == '0')
      idx++;
    return idx == res.size() ? "0" : res.substr(idx);
  }
};
// @lc code=end
