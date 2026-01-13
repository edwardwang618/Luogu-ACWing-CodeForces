/*
 * @lc app=leetcode id=1851 lang=cpp
 *
 * [1851] Minimum Interval to Include Each Query
 */

// @lc code=start
class Solution {
public:
  vector<int> minInterval(vector<vector<int>> &is, vector<int> &q) {
    sort(is.begin(), is.end(), [](const auto &a, const auto &b) {
      return a[0] < b[0];
    });
    using PII = pair<int, int>;
    int m = q.size();
    vector<PII> qs;
    qs.reserve(m);
    for (int i = 0; i < m; i++) qs.emplace_back(q[i], i);
    sort(qs.begin(), qs.end());
    priority_queue<PII, vector<PII>, greater<>> heap;
    vector<int> res(m, -1);
    int idx = 0, n = is.size();
    for (auto &[x, qi] : qs) {
      while (idx < n && is[idx][0] <= x) {
        int l = is[idx][0], r = is[idx][1];
        if (r >= x) heap.emplace(r - l + 1, r);
        idx++;
      }
      while (heap.size() && heap.top().second < x) heap.pop();
      if (heap.size()) res[qi] = heap.top().first;
    }
    return res;
  }
};
// @lc code=end
