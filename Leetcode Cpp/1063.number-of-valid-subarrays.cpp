/*
 * @lc app=leetcode id=1063 lang=cpp
 *
 * [1063] Number of Valid Subarrays
 */

// @lc code=start
class Solution {
 public:
  int validSubarrays(vector<int>& A) {
    stack<int> stk;
    int res = 0;
    for (int i = 0; i < A.size(); i++) {
      while (stk.size() && A[stk.top()] > A[i]) {
        res += i - stk.top();
        stk.pop();
      }

      stk.push(i);
    }

    while (stk.size()) {
      res += A.size() - stk.top();
      stk.pop();
    }

    return res;
  }
};
// @lc code=end
