/*
 * @lc app=leetcode id=2421 lang=cpp
 *
 * [2421] Number of Good Paths
 */

// @lc code=start
class Solution {
public:
  int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &es) {
    using PII = pair<int, int>;
    int n = vals.size(), m = es.size();
    vector<PII> v;
    v.reserve(n);
    for (int i = 0; i < n; i++)
      v.emplace_back(vals[i], i);
    sort(v.begin(), v.end());
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (auto &e : es) {
      int x = e[0], y = e[1];
      add(x, y), add(y, x);
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    auto merge = [&](int x, int y) {
      int px = find(x), py = find(y);
      if (px == py)
        return;
      p[px] = py;
    };

    int res = 0;
    for (int i = 0; i < n; i++) {
#define x first
#define y second
      int j = i;
      while (j < n && v[j].x == v[i].x) {
        int u = v[j++].y;
        for (int k = h[u]; ~k; k = ne[k])
          if (vals[e[k]] <= vals[u])
            merge(u, e[k]);
      }
      unordered_map<int, int> mp;
      for (int k = i; k < j; k++) {
        int u = v[k].y;
        ++mp[find(u)];
      }
#undef x
#undef y
      for (auto &[_, cnt] : mp)
        res += cnt * (cnt - 1) / 2;
      i = j - 1;
    }

    res += n;
    return res;
  }
};
// @lc code=end
