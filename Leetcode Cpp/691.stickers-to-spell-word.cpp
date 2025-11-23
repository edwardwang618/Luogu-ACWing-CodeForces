/*
 * @lc app=leetcode id=691 lang=cpp
 *
 * [691] Stickers to Spell Word
 */

// @lc code=start
class Solution {
 public:
#define N (1 << 15)
#define INF 2e9
  int n, f[N], g[N][26];
  int minStickers(vector<string>& stickers, string target) {
    memset(f, -1, sizeof f);
    memset(g, -1, sizeof g);
    n = target.size();

    int res = dfs(0, stickers, target);
    return res == INF ? -1 : res;
  }

  int fill(int x, char ch, string& t) {
    int& v = g[x][ch - 'a'];
    if (~v) return v;
    v = x;
    for (int i = 0; i < n; i++)
      if (!(x >> i & 1) && t[i] == ch) {
        v += 1 << i;
        break;
      }
    return v;
  }

  int dfs(int x, vector<string>& ss, string& t) {
    if (~f[x]) return f[x];
    if (x == (1 << n) - 1) return f[x] = 0;
    f[x] = INF;
    for (auto& s : ss) {
      int cur = x;
      for (char ch : s) cur = fill(cur, ch, t);
      if (cur != x) f[x] = min(f[x], dfs(cur, ss, t) + 1);
    }

    return f[x];
  }
};
// @lc code=end
