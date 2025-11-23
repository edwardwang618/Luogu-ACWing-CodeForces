/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& a) {
    int res = 0, m = a.size(), n = a[0].size();
    vector<int> f(n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) f[j] = a[i][j] == '0' ? 0 : f[j] + 1;
      res = max(res, calc(f));
    }
    return res;
  }

  // h为每个位置的柱的高度，返回的是以这样的高度能找到的最大矩形面积，可以用单调栈来做
  int calc(auto& h) {
    int res = 0, n = h.size();
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < n; i++) {
      while (~stk.top() && h[stk.top()] > h[i]) {
        int top = stk.top();
        stk.pop();
        res = max(res, h[top] * (i - stk.top() - 1));
      }

      stk.push(i);
    }

    while (~stk.top()) {
      int top = stk.top();
      stk.pop();
      res = max(res, h[top] * (n - stk.top() - 1));
    }

    return res;
  }
};
// @lc code=end
