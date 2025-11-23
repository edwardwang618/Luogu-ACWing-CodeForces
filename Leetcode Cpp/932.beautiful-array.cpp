/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> beautifulArray(int n) {
    if (n == 1) return {1};
    vector<int> l = beautifulArray((n + 1) / 2);
    vector<int> r;
    if (n % 2) r = beautifulArray(n / 2);
    else r = l;
    vector<int> res;
    for (int x : l) res.push_back(2 * x - 1);
    for (int x : r) res.push_back(2 * x);
    return res;
  }
};
// @lc code=end
