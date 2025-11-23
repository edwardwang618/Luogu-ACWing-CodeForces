/*
 * @lc app=leetcode id=1762 lang=cpp
 *
 * [1762] Buildings With an Ocean View
 */

// @lc code=start
class Solution {
 public:
  vector<int> findBuildings(vector<int>& h) {
    vector<int> res;
    stack<int> stk;
    for (int i = h.size() - 1; i >= 0; i--) {
      while (stk.size() && h[stk.top()] < h[i]) stk.pop();
      if (stk.empty()) res.push_back(i);
      stk.push(i);
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
