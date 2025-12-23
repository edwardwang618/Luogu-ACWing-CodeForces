/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
class Solution {
public:
  int slidingPuzzle(vector<vector<int>> &g) {
    string st, ed = "123450";
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 3; j++)
        st += char('0' + g[i][j]);
    if (st == ed) return 0;
    unordered_set<string> vis;
    vis.insert(st);
    queue<string> q;
    q.push(st);
    int res = 0;
    while (q.size()) {
      res++;
      for (int i = q.size(); i; i--) {
        auto t = q.front(); q.pop();
        int idx = t.find('0');
        int x = idx / 3, y = idx % 3;
        static int d[] = {1, 0, -1, 0, 1};
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          if (0 <= nx && nx < 2 && 0 <= ny && ny < 3) {
            int nidx = nx * 3 + ny;
            swap(t[idx], t[nidx]);
            if (t == ed) return res;
            auto [_, ins] = vis.emplace(t);
            if (ins) q.push(t);
            swap(t[idx], t[nidx]);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
