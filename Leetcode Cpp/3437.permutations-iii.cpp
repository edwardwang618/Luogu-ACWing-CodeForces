/*
 * @lc app=leetcode id=3437 lang=cpp
 *
 * [3437] Permutations III
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> permute(int n) {
    vector<vector<int>> res;
    vector<int> v;
    v.reserve(n);
    vector<bool> used(n);
    auto dfs = [&](this auto &&dfs) -> void {
      if (v.size() == n) {
        res.push_back(v);
        return;
      }

      int u, step;
      if (v.empty()) u = 1, step = 1;
      else u = v.back() % 2 + 1, step = 2;
      
      for (int i = u; i <= n; i += step)
        if (!used[i]) {
          used[i] = true;
          v.push_back(i);
          dfs();
          used[i] = false;
          v.pop_back();
        }
    };
    dfs();
    return res;
  }
};
// @lc code=end
