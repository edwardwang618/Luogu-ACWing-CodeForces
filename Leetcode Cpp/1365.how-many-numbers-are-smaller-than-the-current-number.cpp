/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int pre[101];
    memset(pre, 0, sizeof pre);
    for (auto x : nums) pre[x]++;
    for (int i = 1; i <= 100; i++) pre[i] += pre[i - 1];

    vector<int> res;
    for (auto x : nums)
      if (!x)
        res.push_back(0);
      else
        res.push_back(pre[x - 1]);

    return res;
  }
};
// @lc code=end
