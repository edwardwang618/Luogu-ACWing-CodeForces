/*
 * @lc app=leetcode id=2342 lang=cpp
 *
 * [2342] Max Sum of a Pair With Equal Sum of Digits
 */

// @lc code=start
class Solution {
public:
  int maximumSum(vector<int> &a) {
    int n = a.size();
    unordered_map<int, int> mp;
    auto f = [](int x) {
      int sum = 0;
      while (x) {
        sum += x % 10;
        x /= 10;
      }
      return sum;
    };
    int res = -1;
    for (int i = 0; i < n; i++) {
      int x = a[i], s = f(x);
      auto [it, ins] = mp.emplace(s, x);
      if (!ins) {
        res = max(res, it->second + x);
        it->second = max(it->second, x);
      }
    }
    return res;
  }
};
// @lc code=end
