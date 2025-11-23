/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution {
 public:
  vector<int> finalPrices(vector<int>& v) {
    stack<int> stk;
    for (int i = 0; i < v.size(); i++) {
      while (stk.size() && v[stk.top()] >= v[i]) {
        v[stk.top()] -= v[i];
        stk.pop();
      }
      stk.push(i);
    }
    return v;
  }
};
// @lc code=end
