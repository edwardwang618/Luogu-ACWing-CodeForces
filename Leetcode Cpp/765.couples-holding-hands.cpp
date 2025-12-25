/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 */

// @lc code=start
class Solution {
public:
  int minSwapsCouples(vector<int> &a) {
    int n = a.size();
    vector<int> p(n / 2), sz(n / 2, 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    for (int i = 0; i < n; i += 2) {
      int x = a[i] / 2, y = a[i + 1] / 2;
      int px = find(x), py = find(y);
      if (px == py) continue;
      p[px] = py;
      sz[py] += sz[px];
    }

    int res = 0;
    for (int i = 0; i < n / 2; i++)
      if (i == find(i)) res += sz[i] - 1;
    return res;
  }
};
// @lc code=end
