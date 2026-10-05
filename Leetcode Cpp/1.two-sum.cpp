/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &a, int t) {
    size_t n = a.size();
    unordered_map<int, int> mp;
    mp.reserve(n);
    for (int i = 0; i < n; i++) {
      if (auto it = mp.find(t - a[i]); it != mp.end())
        return {it->second, i};
      mp.try_emplace(a[i], i);
    }
    
    return {};
  }
};
// @lc code=end
