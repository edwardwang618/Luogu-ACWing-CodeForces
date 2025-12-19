/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
class Solution {
public:
  int findLHS(vector<int> &a) {
    unordered_map<int, int> mp;
    for (int x : a) ++mp[x];
    int res = 0;
    for (auto &[k, v] : mp) {
      auto it = mp.find(k + 1);
      if (it != mp.end()) res = max(res, v + it->second);
    }
    return res;
  }
};
// @lc code=end
