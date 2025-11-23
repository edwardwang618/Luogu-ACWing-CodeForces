/*
 * @lc app=leetcode id=1222 lang=cpp
 *
 * [1222] Queens That Can Attack the King
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
#define x first
#define y second
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& qs,
                                          vector<int>& king) {
    auto phash = [](const PII& p) {
      return hash<int>()(p.x) ^ hash<int>()(p.y);
    };
    unordered_set<PII, decltype(phash)> st(0, phash);
    for (auto& q : qs) st.insert({q[0], q[1]});
    int x = king[0], y = king[1];
    vector<vector<int>> res;
    for (int dx = -1; dx <= 1; dx++)
      for (int dy = -1; dy <= 1; dy++) {
        if (dx || dy) {
          for (int s = 1;; s++) {
            int nx = x + s * dx, ny = y + s * dy;
            if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
              if (st.count({nx, ny})) {
                res.push_back({nx, ny});
                break;
              }
            } else break;
          }
        }
      }

    return res;
  }
};
// @lc code=end
