/*
 * @lc app=leetcode id=1104 lang=cpp
 *
 * [1104] Path In Zigzag Labelled Binary Tree
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  vector<int> pathInZigZagTree(int label) {
    vector<int> res;
    ll lower = 1LL, upper = 1LL << 32;
    while (lower < label) lower <<= 1;
    if (lower > label) lower >>= 1;
    while (upper > label) upper >>= 1;
    upper = upper * 2 - 1;
    res.push_back(label);

    while (label > 1) {
      lower >>= 1;
      upper >>= 1;
      label = (int)(lower + upper - label / 2);
      res.push_back(label);
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
