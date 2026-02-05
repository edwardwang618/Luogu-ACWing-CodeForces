/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
  int numTrees(int n) {
    vector<int> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < i; j++)
        f[i] += f[j] * f[i - 1 - j];
    return f[n];
  }
};
// @lc code=end
