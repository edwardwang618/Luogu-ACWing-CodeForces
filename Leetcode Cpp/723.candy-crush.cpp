/*
 * @lc app=leetcode id=723 lang=cpp
 *
 * [723] Candy Crush
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
#define x first
#define y second
  vector<vector<int>> candyCrush(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size();
    auto phash = [](const PII& p) {
      auto h = hash<int>();
      return h(p.x) ^ h(p.y);
    };

    auto mark = [&] {
      unordered_set<PII, decltype(phash)> st(0, phash);
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
          if (!a[i][j]) continue;
          int x = a[i][j];
          if (i - 1 >= 0 && a[i - 1][j] == x && i + 1 < m && a[i + 1][j] == x) {
            st.insert({i, j});
            st.insert({i - 1, j});
            st.insert({i + 1, j});
          }
          if (j - 1 >= 0 && a[i][j - 1] == x && j + 1 < n && a[i][j + 1] == x) {
            st.insert({i, j});
            st.insert({i, j - 1});
            st.insert({i, j + 1});
          }
        }
      return st;
    };

    auto crush = [&](unordered_set<PII, decltype(phash)>& st) {
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
          if (!a[i][j] || !st.count({i, j})) continue;
          int k = i;
          st.erase({i, j});
          while (k + 1 < m && st.count({k + 1, j})) {
            st.erase({k + 1, j});
            k++;
          }
          int k1 = i - 1;
          while (k1 >= 0) a[k--][j] = a[k1--][j];
          while (k >= 0 && a[k][j]) a[k--][j] = 0;
        }
    };

    while (true) {
      auto st = mark();
      if (st.empty()) break;
      crush(st);
    }
    return a;
  }
};
// @lc code=end
