/*
 * @lc app=leetcode id=749 lang=cpp
 *
 * [749] Contain Virus
 */

// @lc code=start
#define x first
#define y second
using PII = pair<int, int>;
auto phash = [](const PII& p) { return hash<int>()(p.x) ^ hash<int>()(p.y); };
vector<PII> v;
unordered_set<PII, decltype(phash)> st(0, phash);
int m, n;

class Solution {
 public:
  int dfs(int x, int y, vector<PII>& v, unordered_set<PII, decltype(phash)>& st,
          vector<vector<bool>>& vis, vector<vector<int>>& g) {
    static int d[] = {-1, 0, 1, 0, -1};
    vis[x][y] = true;
    v.push_back({x, y});
    int res = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + d[i], ny = y + d[i + 1];
      if (0 <= nx && nx < m && 0 <= ny && ny < n) {
        if (!g[nx][ny])
          st.insert({nx, ny}), res++;
        else if (g[nx][ny] == 1 && !vis[nx][ny])
          res += dfs(nx, ny, v, st, vis, g);
      }
    }

    return res;
  }

  int find(vector<vector<int>>& g) {
    int cnt = 0, res = 0;
    vector<PII> ps;
    vector<unordered_set<PII, decltype(phash)>> ss;
    vector<vector<bool>> vis(m, vector<bool>(n));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (g[i][j] == 1 && !vis[i][j]) {
          v.clear(), st.clear();
          int t = dfs(i, j, v, st, vis, g);
          if (st.size() > cnt) {
            cnt = st.size();
            res = t;
            ps = v;
          }

          ss.push_back(st);
        }
      }

    for (auto& p : ps) g[p.x][p.y] = -1;
    for (auto& s : ss)
      if (s.size() != cnt)
        for (auto& p : s) g[p.x][p.y] = 1;
    return res;
  }

  int containVirus(vector<vector<int>>& g) {
    m = g.size(), n = g[0].size();
    int cnt = 0, res = 0;
    while (cnt = find(g)) res += cnt;
    return res;
  }
};
// @lc code=end
