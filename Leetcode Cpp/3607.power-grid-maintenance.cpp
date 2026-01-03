/*
 * @lc app=leetcode id=3607 lang=cpp
 *
 * [3607] Power Grid Maintenance
 */

// @lc code=start
class Solution {
public:
  vector<int> processQueries(int c, vector<vector<int>> &es,
                             vector<vector<int>> &qs) {
    vector<int> p(c + 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };

    for (auto &e : es) {
      int pa = find(e[0]), pb = find(e[1]);
      if (pa != pb) p[pa] = pb;
    }

    unordered_map<int, set<int>> online;
    for (int i = 1; i <= c; i++)
      online[find(i)].insert(i);

    vector<int> res;
    for (auto &q : qs) {
      int type = q[0], x = q[1];
      auto &st = online[find(x)];
      if (type == 1) {
        if (st.empty()) res.push_back(-1);
        else if (st.count(x)) res.push_back(x);
        else res.push_back(*st.begin());
      } else st.erase(x);
    }
    return res;
  }
};
// @lc code=end
