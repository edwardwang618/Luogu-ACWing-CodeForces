/*
 * @lc app=leetcode id=1386 lang=cpp
 *
 * [1386] Cinema Seat Allocation
 */

// @lc code=start
class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& v) {
    unordered_map<int, int> mp;
    for (auto& e : v) mp[e[0]] |= 1 << e[1] - 1;
    int res = 0;
    const int full = (1 << 4) - 1;
    for (auto& [k, x] : mp) {
      if (!(x >> 1 & full) && !(x >> 5 & full))
        res += 2;
      else if (!(x >> 1 & full) || !(x >> 3 & full) || !(x >> 5 & full))
        res++;
    }

    res += 2 * (n - mp.size());
    return res;
  }
};
// @lc code=end
