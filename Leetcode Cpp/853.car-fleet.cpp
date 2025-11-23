/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution {
 public:
  int carFleet(int t, vector<int>& pos, vector<int>& speed) {
    int n = pos.size();
    vector<int> id;
    for (int i = 0; i < n; i++) id.push_back(i);
    sort(id.begin(), id.end(), [&](int x, int y) { return pos[x] < pos[y]; });

    int res = n;
    double last = 0;
    for (int i = n - 1; i >= 0; i--) {
      int idx = id[i];
      double time = (double)(t - pos[idx]) / speed[idx];
      if (time <= last)
        res--;
      else
        last = time;
    }

    return res;
  }
};
// @lc code=end
