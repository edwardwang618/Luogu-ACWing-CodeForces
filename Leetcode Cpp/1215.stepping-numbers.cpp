/*
 * @lc app=leetcode id=1215 lang=cpp
 *
 * [1215] Stepping Numbers
 */

// @lc code=start
class Solution {
 public:
  vector<int> countSteppingNumbers(int low, int high) {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    v.reserve(3000);
    for (int i = 1; v.back() < high; i++) {
      int x1 = v[i] % 10 - 1, x2 = v[i] % 10 + 1;
      if (x1 >= 0) v.push_back(v[i] * 10 + x1);
      if (x2 <= 9) v.push_back(v[i] * 10 + x2);
    }
    auto lb = lower_bound(v.begin(), v.end(), low);
    auto ub = upper_bound(v.begin(), v.end(), high);
    return vector<int>(lb, ub);
  }
};

// @lc code=end
