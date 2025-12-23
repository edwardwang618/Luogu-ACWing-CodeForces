/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
class Solution {
public:
  bool isMonotonic(vector<int> &a) {
    int n = a.size();
    bool b1 = true, b2 = true;
    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1])
        b1 = false;
      if (a[i] > a[i - 1])
        b2 = false;
      if (!b1 && !b2)
        return false;
    }
    return true;
  }
};
// @lc code=end
