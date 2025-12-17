/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& a, int k) {
    int n = a.size();
    vector<int> res;
    res.reserve(n - k + 1);
    deque<int> dq;
    for (int i = 0; i < n; i++) {
      while (dq.size() && a[dq.back()] <= a[i]) dq.pop_back();
      if (dq.size() && i - dq.front() >= k) dq.pop_front();
      dq.push_back(i);
      if (i >= k - 1) res.push_back(a[dq.front()]);
    }

    return res;
  }
};
// @lc code=end
