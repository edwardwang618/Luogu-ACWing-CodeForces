/*
 * @lc app=leetcode id=2076 lang=cpp
 *
 * [2076] Process Restricted Friend Requests
 */

// @lc code=start
class Solution {
public:
  vector<bool> friendRequests(int n, vector<vector<int>> &rs,
                              vector<vector<int>> &es) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    vector<bool> res;
    for (auto &e : es) {
      int a = e[0], b = e[1];
      int pa = find(a), pb = find(b);

      res.push_back([&]() {
        for (auto &r : rs) {
          int pu = find(r[0]), pv = find(r[1]);
          if (pa == pu && pb == pv || pa == pv && pb == pu)
            return false;
        }
        p[pa] = pb;
        return true;
      }());
    }
    return res;
  }
};
// @lc code=end
