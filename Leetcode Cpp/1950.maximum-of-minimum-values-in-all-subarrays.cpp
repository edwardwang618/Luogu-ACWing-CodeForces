/*
 * @lc app=leetcode id=1950 lang=cpp
 *
 * [1950] Maximum of Minimum Values in All Subarrays
 */

// @lc code=start
class Solution {
 public:
  vector<int> findMaximums(vector<int>& A) {
    int n = A.size();
    vector<int> res(n);
    stack<int> stk;
    for (int i = 0; i <= n; i++) {
      while (stk.size() && (i == n || A[stk.top()] > A[i])) {
        int t = stk.top(), k = i - 1;
        stk.pop();
        if (stk.size()) k -= stk.top() + 1;
        res[k] = max(res[k], A[t]);
      }

      stk.push(i);
    }

    for (int i = res.size() - 1; i; i--) res[i - 1] = max(res[i - 1], res[i]);
    return res;
  }
};
// @lc code=end
