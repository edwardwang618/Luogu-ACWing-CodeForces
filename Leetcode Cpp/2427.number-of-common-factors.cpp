/*
 * @lc app=leetcode id=2427 lang=cpp
 *
 * [2427] Number of Common Factors
 */

// @lc code=start
class Solution {
 public:
  int commonFactors(int a, int b) {
    unordered_map<int, int> mp;
    divide(gcd(a, b), mp);
    int res = 1;
    for (auto& [k, v] : mp) res *= v + 1;
    return res;
  }

  void divide(int n, unordered_map<int, int>& mp) {
    for (int i = 2; i <= n / i; i++) {
      if (n % i == 0)
        while (n % i == 0) {
          n /= i;
          mp[i]++;
        }
    }
    if (n >= 2) mp[n]++;
  }

  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
};
// @lc code=end
