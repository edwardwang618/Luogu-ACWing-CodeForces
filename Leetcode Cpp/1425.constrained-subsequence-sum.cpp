/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subsequence Sum
 */

// @lc code=start
class Solution {
public:
  using PII = pair<int, int>;
#define x first
#define y second
  int constrainedSubsetSum(vector<int> &a, int k) {
    int res = -2e9;
    deque<PII> dq;
    for (int i = 0; i < a.size(); i++) {
      if (dq.size() && dq.front().x < i - k) dq.pop_front();
      int x = a[i];
      if (dq.size()) x = max(x, a[i] + dq.front().y);
      while (dq.size() && dq.back().second <= x) dq.pop_back();
      dq.push_back({i, x});
      res = max(res, x);
    }

    return res;
  }
};
// @lc code=end
