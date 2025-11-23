/*
 * @lc app=leetcode id=1073 lang=cpp
 *
 * [1073] Adding Two Negabinary Numbers
 */

// @lc code=start
class Solution {
 public:
  vector<int> addNegabinary(vector<int>& a1, vector<int>& a2) {
    if (a1.size() < a2.size()) swap(a1, a2);
    for (int i = a1.size() - 1, j = a2.size() - 1; i >= 0 && j >= 0; i--, j--)
      a1[i] += a2[j];

    vector<int> res;
    for (int i = a1.size() - 1, t = 0; i >= 0 || t; i--) {
      if (i >= 0) t += a1[i];
      res.push_back(t & 1);
      t = -(t >> 1);
    }

    while (res.size() > 1 && !res.back()) res.pop_back();
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
