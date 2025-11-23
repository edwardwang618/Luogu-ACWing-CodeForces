/*
 * @lc app=leetcode id=2365 lang=cpp
 *
 * [2365] Task Scheduler II
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll taskSchedulerII(vector<int>& tasks, int space) {
    ll cur_day = 0;
    unordered_map<int, ll> mp;
    for (int i = 0; i < tasks.size(); i++) {
      int x = tasks[i];
      if (!mp.count(x)) mp[x] = ++cur_day;
      else {
        ll prev_day = mp[x];
        mp[x] = max(cur_day + 1, prev_day + space + 1);
        cur_day = mp[x];
      }
    }

    return cur_day;
  }
};
// @lc code=end
