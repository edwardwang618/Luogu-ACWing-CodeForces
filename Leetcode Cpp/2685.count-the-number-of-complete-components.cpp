/*
 * @lc app=leetcode id=2685 lang=cpp
 *
 * [2685] Count the Number of Complete Components
 */

// @lc code=start
class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>> &es) {
    vector<int> p(n), esz(n), sz(n, 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };

    for (auto &e : es) {
      int a = e[0], b = e[1];
      a = find(a), b = find(b);
      if (a != b) {
        p[a] = b;
        esz[b] += esz[a];
        sz[b] += sz[a];
      }
      esz[b]++;
    }

    int res = 0;
    for (int i = 0; i < n; i++)
      if (i == find(i) && esz[i] == sz[i] * (sz[i] - 1) / 2)
        res++;

    return res;
  }
};
// @lc code=end
