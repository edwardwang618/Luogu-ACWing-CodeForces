/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
class Solution {
 public:
  int videoStitching(vector<vector<int>>& v, int T) {
    sort(v.begin(), v.end());
    int res = 0;
    for (int i = 0, l = 0, r = 0; i < v.size(); i++) {
      if (v[i][0] > l) return -1;
      int j = i;
      while (j < v.size() && v[j][0] <= l) r = max(r, v[j++][1]);
      i = j - 1;
      res++;
      if (r >= T) return res;
      l = r;
    }

    return -1;
  }
};
// @lc code=end
