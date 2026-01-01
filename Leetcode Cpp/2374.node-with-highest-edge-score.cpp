/*
 * @lc app=leetcode id=2374 lang=cpp
 *
 * [2374] Node With Highest Edge Score
 */

// @lc code=start
class Solution {
public:
  int edgeScore(vector<int> &es) {
    int n = es.size();
    using ll = long long;
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
      s[es[i]] += i;
    return max_element(s.begin(), s.end()) - s.begin();
  }
};
// @lc code=end
