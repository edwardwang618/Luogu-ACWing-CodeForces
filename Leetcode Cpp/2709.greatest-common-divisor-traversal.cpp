/*
 * @lc app=leetcode id=2709 lang=cpp
 *
 * [2709] Greatest Common Divisor Traversal
 */

// @lc code=start
class Solution {
public:
  bool canTraverseAllPairs(vector<int> &a) {
    int n = a.size();
    vector<int> p(n), sz(n, 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    auto merge = [&](int x, int y) -> void {
      int px = find(x), py = find(y);
      if (px == py) return;
      p[px] = py;
      sz[py] += sz[px];
    };

    auto pv = [](int x) {
      vector<int> ps;
      for (int i = 2; i <= x / i; i++)
        if (x % i == 0) {
          ps.push_back(i);
          while (x % i == 0) x /= i;
        }
      if (x > 1) ps.push_back(x);
      return ps;
    };
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      auto ps = pv(a[i]);
      for (int x : ps) {
        auto [it, ins] = mp.emplace(x, i);
        if (!ins) merge(it->second, i);
      }
    }
    return sz[find(0)] == n;
  }
};
// @lc code=end
