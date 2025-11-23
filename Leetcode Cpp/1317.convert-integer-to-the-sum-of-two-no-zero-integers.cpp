/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution {
 public:
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n / 2; i++) {
      int j = n - i;
      if (i + j == n && !~to_string(i).find('0') && !~to_string(j).find('0'))
        return {i, j};
    }

    return {};
  }
};
// @lc code=end
