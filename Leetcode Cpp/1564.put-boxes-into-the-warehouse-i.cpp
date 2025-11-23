/*
 * @lc app=leetcode id=1564 lang=cpp
 *
 * [1564] Put Boxes Into the Warehouse I
 */

// @lc code=start
class Solution {
 public:
  int maxBoxesInWarehouse(vector<int>& b, vector<int>& whs) {
    sort(b.begin(), b.end());
    for (int i = 1; i < whs.size(); i++) whs[i] = min(whs[i], whs[i - 1]);
    int cnt = 0;
    for (int i = whs.size() - 1; i >= 0; i--)
      if (cnt < b.size() && b[cnt] <= whs[i]) cnt++;
    return cnt;
  }
};
// @lc code=end
