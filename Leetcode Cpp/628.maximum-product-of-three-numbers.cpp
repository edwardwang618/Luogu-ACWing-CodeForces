/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
public:
  int maximumProduct(vector<int> &a) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int x : a) {
      // largest three
      if (x > max1) {
        max3 = max2;
        max2 = max1;
        max1 = x;
      } else if (x > max2) {
        max3 = max2;
        max2 = x;
      } else if (x > max3) {
        max3 = x;
      }

      // smallest two
      if (x < min1) {
        min2 = min1;
        min1 = x;
      } else if (x < min2) {
        min2 = x;
      }
    }

    return max(max1 * max2 * max3, min1 * min2 * max1);
  }
};
// @lc code=end
