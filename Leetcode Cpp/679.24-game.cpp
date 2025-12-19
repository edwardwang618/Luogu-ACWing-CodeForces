/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
class Solution {
public:
  bool judgePoint24(vector<int> &v) {
    static constexpr double eps = 1e-6;
    return dfs(v, eps);
  }

  static bool dfs(auto &a, double eps) {
    int n = a.size();
    if (n == 1)
      return abs(a[0] - 24.0) <= eps;

    for (int i = 0; i + 1 < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double x = a[i], y = a[j];
        vector<double> b;
        b.reserve(n - 1);
        for (int k = 0; k < n; k++)
          if (k != i && k != j)
            b.push_back(a[k]);

        auto try_push = [&](double val) {
          b.push_back(val);
          if (dfs(b, eps))
            return true;
          b.pop_back();
          return false;
        };

        if (try_push(x + y) || try_push(x * y) || try_push(x - y) ||
            try_push(y - x))
          return true;

        if (abs(y) > eps && try_push(x / y) || abs(x) > eps && try_push(y / x))
          return true;
      }
    }
    return false;
  }
};
// @lc code=end
