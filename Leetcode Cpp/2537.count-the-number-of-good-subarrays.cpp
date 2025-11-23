/*
 * @lc app=leetcode id=2537 lang=cpp
 *
 * [2537] Count the Number of Good Subarrays
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll countGood(vector<int>& a, int k) {
    ll res = 0;
    unordered_map<int, int> mp;
    ll cnt = 0;
    for (int i = 0, j = 0; i < a.size(); i++) {
      int prev_cnt = mp[a[i]]++, cur_cnt = prev_cnt + 1;
      static auto f = [](ll cur_cnt, ll prev_cnt) {
        return (cur_cnt * (cur_cnt - 1) - prev_cnt * (prev_cnt - 1)) / 2;
      };
      cnt += f(cur_cnt, prev_cnt);
      while (cnt >= k) {
        prev_cnt = mp[a[j++]]--;
        cur_cnt = prev_cnt - 1;
        cnt += f(cur_cnt, prev_cnt);
      }
      res += j;
    }
    return res;
  }
};
// @lc code=end
