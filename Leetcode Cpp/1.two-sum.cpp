/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &A, int t) {
    unordered_map<int, int> mp;
    for (int i = 0; i < A.size(); i++) {
      if (auto it = mp.find(t - A[i]); it != mp.end())
        return {it->second, i};
      mp[A[i]] = i;
    }
    return {};
  }
};
// @lc code=end
