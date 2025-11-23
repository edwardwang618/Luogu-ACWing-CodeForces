/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

// @lc code=start
class Solution {
 public:
  int maxEvents(vector<vector<int>>& es) {
    int n = es.size();
    sort(es.begin(), es.end());
    priority_queue<int, vector<int>, greater<int>> heap;

    int res = 0;
    for (int i = 0, cur = 0; i < n || heap.size();) {
      if (heap.empty()) cur = es[i][0];
      while (i < n && es[i][0] == cur) heap.push(es[i++][1]);
      res++;
      heap.pop();
      while (heap.size() && heap.top() <= cur) heap.pop();
      cur++;
    }

    return res;
  }
};
// @lc code=end
