/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
 public:
  struct Range {
    int min, max;
    bool used;
  };

  int maximumGap(vector<int>& a) {
    int n = a.size();
    int m = INT_MAX, M = INT_MIN;
    for (int x : a) {
      m = min(m, x);
      M = max(M, x);
    }
    if (n < 2 || m == M) return 0;
    int len = (M - m + n - 2) / (n - 1);
    vector<Range> v((M - m + len - 1) / len, {INT_MAX, INT_MIN, false});
    for (int x : a) {
      if (x == m) continue;
      int k = (x - m - 1) / len;
      v[k] = {min(v[k].min, x), max(v[k].max, x), true};
    }

    int res = 0;
    for (int i = 0, prev = m; i < v.size(); i++)
      if (v[i].used) {
        res = max(res, v[i].min - prev);
        prev = v[i].max;
      }

    return res;
  }
};
// @lc code=end
