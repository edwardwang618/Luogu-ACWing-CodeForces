/*
 * @lc app=leetcode id=2445 lang=cpp
 *
 * [2445] Number of Nodes With Value One
 */

// @lc code=start
class Solution {
public:
  int numberOfNodes(int n, vector<int> &qs) {
    vector<int> cnt(n + 1);
    for (int q : qs) cnt[q]++;

    int res = 0;
    for (int i = 1; i <= n; i++) {
      cnt[i] = (cnt[i] + cnt[i / 2]) % 2;
      res += cnt[i];
    }
    return res;
  }
};
// @lc code=end
