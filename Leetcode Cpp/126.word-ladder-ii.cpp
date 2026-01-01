/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> findLadders(string &begin, string &end,
                                     vector<string> &v) {
    vector<vector<string>> res;
    unordered_set<string> st(v.begin(), v.end());
    if (!st.count(end))
      return res;
    st.insert(begin);
    queue<string> q;
    q.push(begin);
    unordered_map<string, int> dist{{begin, 0}};
    unordered_map<string, vector<string>> g;
    int d = 0;
    bool found = false;
    while (q.size()) {
      d++;
      for (int i = q.size(); i; i--) {
        auto s = q.front(); q.pop();
        auto t = s;
        found = [&]() {
          for (char &ch : s) {
            char tmp = ch;
            for (char ne = 'a'; ne <= 'z'; ne++) {
              if (ne == tmp) continue;
              ch = ne;
              if (!st.count(s)) continue;
              auto [it, ins] = dist.emplace(s, d);
              if (ins || it->second == d) {
                g[s].push_back(t);
                if (ins) q.push(s);
              };
              if (s == end) return true;
            }
            ch = tmp;
          }
          return false;
        }();
      }
      if (found) break;
    }

    vector<string> path;
    path.reserve(d + 1);
    auto dfs = [&](this auto &&dfs, string &cur) -> void {
      path.push_back(cur);
      if (cur == begin) res.emplace_back(path.rbegin(), path.rend());
      else for (auto &ne : g[cur]) dfs(ne);
      path.pop_back();
    };
    dfs(end);
    return res;
  }
};
// @lc code=end
