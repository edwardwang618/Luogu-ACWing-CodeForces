/*
 * @lc app=leetcode id=2100 lang=cpp
 *
 * [2100] Find Good Days to Rob the Bank
 */

// @lc code=start
class Solution {
 public:
  vector<int> goodDaysToRobBank(vector<int>& v, int t) {
    int n = v.size();
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++)
      if (!i || v[i - 1] < v[i]) left[i] = 1;
      else left[i] = 1 + left[i - 1];

    for (int i = n - 1; i >= 0; i--)
      if (i == n - 1 || v[i + 1] < v[i]) right[i] = 1;
      else right[i] = 1 + right[i + 1];

    vector<int> res;
    for (int i = 0; i < v.size(); i++)
      if (min(left[i], right[i]) >= t + 1) res.push_back(i);

    return res;
  }
};
// @lc code=end
