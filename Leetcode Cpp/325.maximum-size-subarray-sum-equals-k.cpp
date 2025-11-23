/*
 * @lc app=leetcode id=325 lang=cpp
 *
 * [325] Maximum Size Subarray Sum Equals k
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  int maxSubArrayLen(vector<int>& a, int k) {
    int res = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    ll s = 0;
    for (int i = 0; i < a.size(); i++) {
      s += a[i];
      if (mp.count(s - k)) res = max(res, i - mp[s - k]);
      if (!mp.count(s)) mp[s] = i;
    }
    return res;
  }
};
// @lc code=end
