/*
 * @lc app=leetcode id=2702 lang=cpp
 *
 * [2702] Minimum Operations to Make Numbers Non-positive
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  int minOperations(vector<int>& a, int x, int y) {
    int l = 1, r = 0;
    for (int x : a) r = max(r, x);
    r = (r + y - 1) / y;
    int diff = x - y;
    auto f = [&](int op) {
      ll extra_op = 0;
      for (int z : a) {
        int r = z - y * op;
        if (r > 0) extra_op += ((ll)r + diff - 1) / diff;
      }
      return extra_op <= op;
    };
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (f(mid))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
};
// @lc code=end
