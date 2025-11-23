/*
 * @lc app=leetcode id=2226 lang=cpp
 *
 * [2226] Maximum Candies Allocated to K Children
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  int maximumCandies(vector<int>& cs, ll k) {
    auto f = [&](int x) -> bool {
      ll res = 0;
      for (int c : cs) res += c / x;
      return res >= k;
    };
    int l = 1, r = *max_element(cs.begin(), cs.end());
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (f(mid))
        l = mid;
      else
        r = mid - 1;
    }
    return f(l) ? l : 0;
  }
};
// @lc code=end
