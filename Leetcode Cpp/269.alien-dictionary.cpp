/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Alien Dictionary
 */

// @lc code=start
class Solution {
 public:
  // string alienOrder(vector<string>& ws) {
  // if (ws.size() == 1) {
  //   auto& s = ws[0];
  //   unordered_set<char> st(s.begin(), s.end());
  //   return string(st.begin(), st.end());
  // }

  //   vector<vector<bool>> g(26, vector<bool>(26));
  //   unordered_set<char> st(ws[0].begin(), ws[0].end());
  //   auto cmp = [&](auto& s1, auto& s2) {
  //     st.insert(s2.begin(), s2.end());
  //     int m = s1.size(), n = s2.size();
  //     bool diff = false;
  //     for (int i = 0; i < m && i < n; i++)
  //       if (s1[i] != s2[i]) {
  //         g[s1[i] - 'a'][s2[i] - 'a'] = diff = true;
  //         if (g[s2[i] - 'a'][s1[i] - 'a']) return false;
  //         break;
  //       }
  //     if (!diff && m > n) return false;
  //     return true;
  //   };
  //   for (int i = 0; i + 1 < ws.size(); i++)
  //     if (!cmp(ws[i], ws[i + 1])) return "";
  //   string res;
  //   vector<int> vis(26, -1);
  //   for (char ch : st)
  //     if (!~vis[ch - 'a'])
  //       if (!dfs(ch - 'a', g, vis, res)) return "";

  //   reverse(res.begin(), res.end());
  //   return res;
  // }

  // bool dfs(int u, auto& g, auto& vis, string& res) {
  //   vis[u] = 0;
  //   for (int ne = 0; ne < 26; ne++)
  //     if (g[u][ne]) {
  //       if (!vis[ne])
  //         return false;
  //       else if (!~vis[ne] && !dfs(ne, g, vis, res))
  //         return false;
  //     }
  //   vis[u] = 1;
  //   res.push_back('a' + u);
  //   return true;
  // }

  string alienOrder(vector<string>& ws) {
    if (ws.size() == 1) {
      auto& s = ws[0];
      unordered_set<char> st(s.begin(), s.end());
      return string(st.begin(), st.end());
    }

    vector<vector<bool>> g(26, vector<bool>(26));
    unordered_set<char> st(ws[0].begin(), ws[0].end());
    auto cmp = [&](auto& s1, auto& s2) {
      st.insert(s2.begin(), s2.end());
      int m = s1.size(), n = s2.size();
      bool diff = false;
      for (int i = 0; i < m && i < n; i++)
        if (s1[i] != s2[i]) {
          g[s1[i] - 'a'][s2[i] - 'a'] = diff = true;
          if (g[s2[i] - 'a'][s1[i] - 'a']) return false;
          break;
        }
      if (!diff && m > n) return false;
      return true;
    };
    for (int i = 0; i + 1 < ws.size(); i++)
      if (!cmp(ws[i], ws[i + 1])) return "";
    unordered_map<int, int> ind;
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++)
        if (g[i][j]) ind[j]++;
    queue<int> q;
    for (char ch : st)
      if (!ind.count(ch - 'a')) q.push(ch - 'a');
    string res;
    while (q.size()) {
      auto t = q.front();
      q.pop();
      res += 'a' + t;
      for (int ne = 0; ne < 26; ne++)
        if (g[t][ne] && !--ind[ne]) q.push(ne);
    }
    if (res.size() < st.size()) return "";
    return res;
  }
};
// @lc code=end
