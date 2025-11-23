/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */

// @lc code=start
class Solution {
 public:
  int minTaps(int n, vector<int>& ranges) {
    vector<int> len(n + 1);
    for (int i = 0; i <= n; i++) {
      int st = max(0, i - ranges[i]), ed = min(n, i + ranges[i]);
      len[st] = max(len[st], ed - st);
    }

    int res = 0, r = 0;
    for (int i = 0, far = 0; i < n; i++) {
      if (i > r) return -1;
      far = max(far, i + len[i]);
      if (i == r) res++, r = far;
    }

    return r >= n ? res : -1;
  }
};
// @lc code=end
