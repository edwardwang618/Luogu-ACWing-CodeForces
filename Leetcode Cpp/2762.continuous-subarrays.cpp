/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  ll continuousSubarrays(vector<int> &a) {
    int n = a.size();
    deque<int> minq, maxq;
    ll res = 0;
    for (int i = 0, j = 0; i < n; i++) {
      int x = a[i];
      while (minq.size() && a[minq.back()] >= x) minq.pop_back();
      while (maxq.size() && a[maxq.back()] <= x) maxq.pop_back();
      minq.push_back(i);
      maxq.push_back(i);
      while (a[maxq.front()] - a[minq.front()] > 2) {
        j++;
        if (minq.front() < j) minq.pop_front();
        if (maxq.front() < j) maxq.pop_front();
      }
      res += i - j + 1;
    }
    return res;
  }
};
// @lc code=end
