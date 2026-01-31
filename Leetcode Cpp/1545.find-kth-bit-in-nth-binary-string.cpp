/*
 * @lc app=leetcode id=1545 lang=cpp
 *
 * [1545] Find Kth Bit in Nth Binary String
 */

// @lc code=start
class Solution {
public:
  char findKthBit(int n, int k) {
    auto dfs = [&](this auto &&dfs, int n, int k) -> char {
      if (n == 1)
        return '0';

      int len = (1 << n) - 1;
      int mid = len / 2 + 1;

      if (k == mid)
        return '1';
      else if (k < mid)
        return dfs(n - 1, k);
      else
        return dfs(n - 1, len - k + 1) ^ 1;
    };

    return dfs(n, k);
  }
};
// @lc code=end
