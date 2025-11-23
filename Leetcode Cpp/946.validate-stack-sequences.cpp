/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;
    int idx = 0;
    for (int x : pushed) {
      stk.push(x);
      while (stk.size() && stk.top() == popped[idx]) {
        stk.pop();
        idx++;
      }
    }

    return stk.empty();
  }
};
// @lc code=end
