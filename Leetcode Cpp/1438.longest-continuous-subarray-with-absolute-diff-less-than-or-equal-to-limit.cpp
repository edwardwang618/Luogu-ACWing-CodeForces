/*
 * @lc app=leetcode id=1438 lang=cpp
 *
 * [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to
 * Limit
 */

// @lc code=start
class Solution {
 public:
  // int longestSubarray(vector<int>& a, int l) {
  //   deque<int> dq_max, dq_min;
  //   int res = 0;
  //   for (int i = 0, j = 0; i < a.size(); i++) {
  //     while (dq_max.size() && a[dq_max.back()] <= a[i]) dq_max.pop_back();
  //     while (dq_min.size() && a[dq_min.back()] >= a[i]) dq_min.pop_back();
  //     dq_max.push_back(i);
  //     dq_min.push_back(i);
  //     while (a[dq_max.front()] - a[dq_min.front()] > l) {
  //       j++;
  //       if (j > dq_max.front()) dq_max.pop_front();
  //       if (j > dq_min.front()) dq_min.pop_front();
  //     }

  //     res = max(res, i - j + 1);
  //   }
  //   return res;
  // }

  int longestSubarray(vector<int>& a, int l) {
    map<int, int> mp;
    int res = 0;
    for (int i = 0, j = 0; i < a.size(); i++) {
      mp[a[i]]++;
      while (mp.rbegin()->first - mp.begin()->first > l) {
        mp[a[j]]--;
        if (!mp[a[j]]) mp.erase(a[j]);
        j++;
      }

      res = max(res, i - j + 1);
    }
    return res;
  }
};
// @lc code=end
