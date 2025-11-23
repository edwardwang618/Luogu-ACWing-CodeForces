/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */

// @lc code=start
class Solution {
 public:
  int partitionDisjoint(vector<int>& a) {
    int n = a.size();
    vector<int> b(n);
    for (int i = n - 1; i >= 0; i--)
      if (i == n - 1) b[i] = a[i];
      else b[i] = min(a[i], b[i + 1]);
    
    for (int i = 0, m = a[0]; i + 1 < n; i++) {
      m = max(m, a[i]);
      if (m <= b[i + 1]) return i + 1;
    }

    return -1;
  }
};
// @lc code=end
