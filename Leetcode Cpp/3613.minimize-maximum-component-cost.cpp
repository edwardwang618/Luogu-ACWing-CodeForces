/*
 * @lc app=leetcode id=3613 lang=cpp
 *
 * [3613] Minimize Maximum Component Cost
 */

// @lc code=start
class Solution {
public:
  int minCost(int n, vector<vector<int>> &es, int k) {
    vector<int> ls{0};
    for (auto &e : es)
      ls.push_back(e[2]);
    sort(ls.begin(), ls.end());
    ls.erase(unique(ls.begin(), ls.end()), ls.end());

    vector<int> p(n);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    auto f = [&](int max_l) {
      iota(p.begin(), p.end(), 0);
      int cnt = n;
      for (auto &e : es)
        if (e[2] <= max_l) {
          int a = e[0], b = e[1];
          int pa = find(a), pb = find(b);
          if (pa != pb) {
            p[pa] = pb;
            cnt--;
          }
        }
      return cnt <= k;
    };

    int l = 0, r = ls.size() - 1;
    while (l < r) {
      int mid = l + r >> 1;
      if (f(ls[mid]))
        r = mid;
      else
        l = mid + 1;
    }
    return ls[l];
  }
};
// @lc code=end
