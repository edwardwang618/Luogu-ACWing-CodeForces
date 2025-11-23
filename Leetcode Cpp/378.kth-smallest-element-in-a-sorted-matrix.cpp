/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& g, int k) {
    int n = g.size();
    int l = g[0][0], r = g[n - 1][n - 1];
    auto cnt = [&](int z) {
      int x = 0, y = n - 1, res = 0;
      while (y >= 0 && x < n) {
        if (g[x][y] <= z)
          res += y + 1, x++;
        else
          y--;
      }
      return res;
    };
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (cnt(mid) >= k)
        r = mid;
      else
        l = mid + 1;
    }

    return l;
  }
};
// @lc code=end
