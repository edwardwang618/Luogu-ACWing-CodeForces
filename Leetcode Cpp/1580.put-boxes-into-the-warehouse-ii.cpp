/*
 * @lc app=leetcode id=1580 lang=cpp
 *
 * [1580] Put Boxes Into the Warehouse II
 */

// @lc code=start
class Solution {
 public:
  int maxBoxesInWarehouse(vector<int>& b, vector<int>& whs) {
    sort(b.begin(), b.end(), greater<int>());
    int res = 0;
    for (int i = 0, j = whs.size() - 1, idx = 0; i <= j; idx++) {
      if (idx == b.size()) break;
      if (b[idx] <= whs[i])
        i++, res++;
      else if (b[idx] <= whs[j])
        j--, res++;
    }

    return res;
  }
};
// @lc code=end
