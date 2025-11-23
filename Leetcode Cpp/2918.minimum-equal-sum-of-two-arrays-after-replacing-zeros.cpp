/*
 * @lc app=leetcode id=2918 lang=cpp
 *
 * [2918] Minimum Equal Sum of Two Arrays After Replacing Zeros
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  ll minSum(vector<int>& a, vector<int>& b) {
    auto f = [&](vector<int>& a) -> pair<ll, int> {
      ll sum = 0;
      int cnt = 0;
      for (int i = 0; i < a.size(); i++)
        if (!a[i]) cnt++;
        else sum += a[i];
      return {sum, cnt};
    };
    auto p1 = f(a), p2 = f(b);
    ll sum1 = p1.first, sum2 = p2.first;
    int cnt1 = p1.second, cnt2 = p2.second;
    sum1 += cnt1;
    sum2 += cnt2;
    if (sum1 > sum2) {
      if (!cnt2) return -1;
      else return sum1;
    } else if (sum1 < sum2) {
      if (!cnt1) return -1;
      else return sum2;
    } else return sum1;
  }
};
// @lc code=end
