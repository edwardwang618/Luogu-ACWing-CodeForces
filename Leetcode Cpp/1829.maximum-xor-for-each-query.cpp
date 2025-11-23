/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int m) {
    vector<int> res;
    for (int i = 0, sum = 0; i < nums.size(); i++) {
      sum ^= nums[i];
      res.push_back(sum ^ (1 << m) - 1);
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
