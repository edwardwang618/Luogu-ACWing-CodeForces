/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& a) {
    int n = a.size();
    vector<int> res(n, 0);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      while (stk.size() && a[stk.top()] < a[i]) {
        res[stk.top()] = i - stk.top();
        stk.pop();
      }

      stk.push(i);
    }

    return res;
  }
};
// @lc code=end
