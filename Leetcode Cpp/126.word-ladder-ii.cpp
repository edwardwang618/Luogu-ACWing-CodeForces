/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> findLadders(string beg, string end,
                                     vector<string> &ws) {
    vector<vector<string>> res;
    unordered_set<string> set;
    for (auto &s : ws) set.insert(s);
    if (!set.count(end)) return res;
    set.insert(beg);
    unordered_map<string, vector<string>> g;
    unordered_map<string, int> dist;
    dist[end] = 0;

    queue<string> q;
    q.push(end);
    while (q.size()) {
      auto s = q.front();
      q.pop();
      auto t = s;
      for (int i = 0; i < s.size(); i++) {
        char old = s[i];
        for (char ch = 'a'; ch <= 'z'; ch++) {
          if (ch == old) continue;

          s[i] = ch;
          if (set.count(s))
            if (!dist.count(s) || dist[s] == dist[t] + 1) {
              g[s].push_back(t);
              if (!dist.count(s)) q.push(s);

              dist[s] = dist[t] + 1;
              if (s == beg) break;
            }
        }

        s[i] = old;
      }
    }

    if (!dist.count(beg)) return res;
    vector<string> v;
    dfs(beg, dist, v, res, g);
    return res;
  }

  void dfs(string &s, unordered_map<string, int> &dist, vector<string> &v,
           vector<vector<string>> &res,
           unordered_map<string, vector<string>> &g) {
    v.push_back(s);
    if (!dist[s]) {
      res.push_back(v);
      v.pop_back();
      return;
    }

    for (auto &ne : g[s]) dfs(ne, dist, v, res, g);
    v.pop_back();
  }
};
// @lc code=end
