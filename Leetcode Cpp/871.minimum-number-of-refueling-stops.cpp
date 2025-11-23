/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution {
 public:
  int minRefuelStops(int t, int fuel, vector<vector<int>>& ss) {
    int res = 0, x = fuel;
    priority_queue<int> heap;
    auto it = ss.begin();
    while (x < t) {
      while (it != ss.end() && it->at(0) <= x) {
        heap.push(it->at(1));
        it++;
      }
      if (heap.empty()) return -1;
      x += heap.top(); heap.pop();
      res++;
    }

    return res;
  }
};
// @lc code=end
