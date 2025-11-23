/*
 * @lc app=leetcode id=1944 lang=cpp
 *
 * [1944] Number of Visible People in a Queue
 */

// @lc code=start
class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& hs) {
    int n = hs.size();
    vector<int> res(n, 0);
    stack<int> stk;
    for (int i = n - 1; i >= 0; i--) {
      while (stk.size() && hs[i] > hs[stk.top()]) {
        res[i]++;
        stk.pop();
      }

      if (stk.size()) res[i]++;
      stk.push(i);
    }

    return res;
  }
};
// @lc code=end
