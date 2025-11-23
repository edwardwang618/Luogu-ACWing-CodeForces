/*
 * @lc app=leetcode id=1447 lang=cpp
 *
 * [1447] Simplified Fractions
 */

// @lc code=start
class Solution {
 public:
  vector<string> simplifiedFractions(int n) {
    vector<string> res;
    for (int i = 2; i <= n; i++)
      for (int j = 1; j < i; j++)
        if (gcd(i, j) == 1) 
          res.push_back(to_string(j) + "/" + to_string(i));
    
    return res;
  }

  int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
  }
};
// @lc code=end
