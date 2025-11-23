/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& l1,
                                           vector<vector<int>>& l2) {
    vector<vector<int>> res;
    for (int i = 0, j = 0; i < l1.size() && j < l2.size();) {
      int l = max(l1[i][0], l2[j][0]), r = min(l1[i][1], l2[j][1]);
      if (l <= r) res.push_back({l, r});
      if (l1[i][1] < l2[j][1])
        i++;
      else
        j++;
    }

    return res;
  }
};
// @lc code=end
