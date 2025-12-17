/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
  using PII = pair<int, int>;
  using u32 = uint32_t;
  using u64 = uint64_t;

  int maxPoints(vector<vector<int>> &ps) {
    int n = ps.size();
    int res = 1;
    auto ha = [](const PII &p) {
      return (u64)(u32)p.first << 32 ^ (u32)p.second;
    };
    auto gcd = [](int x, int y) {
      while (y) {
        int t = x % y;
        x = y;
        y = t;
      }
      return x;
    };
    for (int i = 0; i < n; i++) {
      unordered_map<PII, int, decltype(ha)> mp;
      mp.reserve(2 * n);
      int dup = 0;
      int cnt = 0;
      int x1 = ps[i][0], y1 = ps[i][1];
      for (int j = i + 1; j < n; j++) {
        int x2 = ps[j][0], y2 = ps[j][1];
        int dx = x2 - x1, dy = y2 - y1;
        if (!dx && !dy) {
          dup++;
          continue;
        }
        if (!dx)
          dy = 1;
        else if (!dy)
          dx = 1;
        else {
          int g = gcd(dx, dy);
          dx /= g;
          dy /= g;
          if (dx < 0)
            dx = -dx, dy = -dy;
        }

        cnt = max(cnt, ++mp[{dx, dy}]);
      }
      res = max(res, cnt + dup + 1);
    }
    return res;
  }
};
// @lc code=end
