/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution {
public:
  vector<int> relativeSortArray(vector<int> &a1, vector<int> &a2) {
    vector<int> cnt(1001);
    for (int x : a1) cnt[x]++;
    int idx = 0;
    for (int x : a2)
      while (cnt[x]-- > 0) a1[idx++] = x;
    for (int i = 0; i <= 1000; i++)
      while (cnt[i]-- > 0) a1[idx++] = i;
    return a1;
  }
};
// @lc code=end
