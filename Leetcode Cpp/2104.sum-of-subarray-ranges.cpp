/*
 * @lc app=leetcode id=2104 lang=cpp
 *
 * [2104] Sum of Subarray Ranges
 */
class Solution {
 public:
  using LL = long long;

  LL subArrayRanges(vector<int>& nums) {
    auto less = [](int& x, int& y) { return x <= y; };
    auto more = [](int& x, int& y) { return x >= y; };
    return calc(nums, more) - calc(nums, less);
  }

  LL calc(vector<int>& v, bool (*comp)(int&, int&)) {
    stack<int> stk;
    LL res = 0;
    for (int i = 0; i < v.size(); i++) {
      while (stk.size() && comp(v[i], v[stk.top()])) {
        int idx = stk.top(); stk.pop();
        int l = idx - (stk.size() ? stk.top() : -1), r = i - idx;
        res += (LL)v[idx] * l * r;
      }
      stk.push(i);
    }

    while (stk.size()) {
      int idx = stk.top(); stk.pop();
      int l = idx - (stk.size() ? stk.top() : -1), r = v.size() - idx;
      res += (LL)v[idx] * l * r;
    }

    return res;
  }
};
// @lc code=start
