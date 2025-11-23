/*
 * @lc app=leetcode id=2355 lang=cpp
 *
 * [2355] Maximum Number of Books You Can Take
 */

// @lc code=start
class Solution {
 public:
  using LL = long long;
  LL maximumBooks(vector<int>& v) {
    int n = v.size();
    stack<int> stk;
    long res = 0;
    vector<long> f(n);
    for (int i = 0; i < n; i++) {
      while (stk.size() && v[stk.top()] > v[i] - (i - stk.top())) stk.pop();
      if (stk.size()) {
        int len = i - stk.top();
        f[i] = f[stk.top()] + (long)(v[i] + v[i] - len + 1) * len / 2;
      } else {
        int len = v[i] - i <= 0 ? v[i] : i + 1;
        f[i] = (long)(v[i] + v[i] - len + 1) * len / 2;
      }
      res = max(res, f[i]);
      stk.push(i);
    }
    return res;
  }
};
// @lc code=end
