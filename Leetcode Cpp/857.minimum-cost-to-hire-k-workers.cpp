/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */

// @lc code=start
class Solution {
public:
  double mincostToHireWorkers(vector<int> &q, vector<int> &w, int k) {
    int n = q.size();
    vector<pair<double, int>> v;
    for (int i = 0; i < n; i++)
      v.emplace_back((double)w[i] / q[i], q[i]);
    sort(v.begin(), v.end());
    priority_queue<int> heap;
    double res = 9e18, sum = 0;
    for (auto &p : v) {
      sum += p.second;
      heap.push(p.second);
      if (heap.size() > k) {
        sum -= heap.top();
        heap.pop();
      }

      if (heap.size() == k) res = min(res, sum * p.first);
    }
    return res;
  }
};
// @lc code=end
