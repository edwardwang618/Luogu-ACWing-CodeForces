/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
#define x first
#define y second
  int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
    static int d[] = {0, 1, 0, -1, 0};
    auto phash = [](const PII& p) {
      auto h = hash<int>();
      return h(p.x) ^ h(p.y);
    };
    unordered_set<PII, decltype(phash)> st(0, phash);
    for (auto& o : obs) st.insert({o[0], o[1]});
    int res = 0, dir = 0, x = 0, y = 0;
    for (int c : commands) {
      if (!~c) dir = (dir + 1) % 4;
      else if (c == -2) dir = (dir + 3) % 4;
      else {
        for (int i = 0; i < c; i++) {
          int nx = x + d[dir], ny = y + d[dir + 1];
          if (st.count({nx, ny})) break;
          x = nx, y = ny;
        }
      }

      res = max(res, x * x + y * y);
    }

    return res;
  }
};
// @lc code=end
