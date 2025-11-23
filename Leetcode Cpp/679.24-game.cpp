/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
class Solution {
 public:
  const double eps = 1e-9;
  bool judgePoint24(vector<int>& v) {
    vector<double> a(v.begin(), v.end());
    return dfs(a);
  }

  bool dfs(vector<double>& a) {
    if (a.size() == 1) return abs(a[0] - 24) < eps;
    for (int i = 0; i + 1 < a.size(); i++)
      for (int j = i + 1; j < a.size(); j++) {
        double x = a[i], y = a[j];
        a.erase(a.begin() + j);
        a.erase(a.begin() + i);

        a.push_back(x + y);
        if (dfs(a)) return true;
        a.back() = x - y;
        if (dfs(a)) return true;
        a.back() = y - x;
        if (dfs(a)) return true;
        a.back() = x * y;
        if (dfs(a)) return true;
        a.pop_back();
        if (abs(y) > eps) {
          a.push_back(x / y);
          if (dfs(a)) return true;
          a.pop_back();
        }
        if (abs(x) > eps) {
          a.push_back(y / x);
          if (dfs(a)) return true;
          a.pop_back();
        }

        a.insert(a.begin() + i, x);
        a.insert(a.begin() + j, y);
      }

    return false;
  }
};
// @lc code=end
