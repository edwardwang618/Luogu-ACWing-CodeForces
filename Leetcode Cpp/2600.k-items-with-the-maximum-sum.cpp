/*
 * @lc app=leetcode id=2600 lang=cpp
 *
 * [2600] K Items With the Maximum Sum
 */

// @lc code=start
class Solution {
public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    if (k <= numOnes) return k;
    if (numOnes < k && k <= numOnes + numZeros) return numOnes;
    return numOnes - (k - numOnes - numZeros);
  }
};
// @lc code=end
