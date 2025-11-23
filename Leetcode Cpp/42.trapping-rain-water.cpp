/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
 public:
  // int trap(vector<int>& h) {
  //   int res = 0;
  //   for (int l = 0, r = h.size() - 1, maxl = h[0], maxr = h.back(); l <= r;)
  //     if (maxl <= maxr)
  //       res += max(0, maxl - h[l]), maxl = max(maxl, h[l]), l++;
  //     else
  //       res += max(0, maxr - h[r]), maxr = max(maxr, h[r]), r--;
  //   return res;
  // }

  // int trap(vector<int>& h) {
  //   int n = h.size();
  //   int fl[n], fr[n];
  //   fl[0] = h[0];
  //   for (int i = 1; i < n; i++) fl[i] = max(fl[i - 1], h[i - 1]);
  //   fr[n - 1] = h[n - 1];
  //   for (int i = n - 2; i >= 0; i--) fr[i] = max(fr[i + 1], h[i + 1]);

  //   int res = 0;
  //   for (int i = 1; i < n - 1; i++) res += max(0, min(fl[i], fr[i]) - h[i]);
  //   return res;
  // }

  int trap(vector<int>& h) {
    int n = h.size();
    int res = 0;
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      while (stk.size() && h[stk.top()] <= h[i]) {
        int tp = stk.top(); stk.pop();
        if (stk.size())
          res += (min(h[stk.top()], h[i]) - h[tp]) * (i - stk.top() - 1);
      }
      stk.push(i);
    }
    return res;
  }
};
// @lc code=end
