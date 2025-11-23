/*
 * @lc app=leetcode id=1307 lang=cpp
 *
 * [1307] Verbal Arithmetic Puzzle
 */

// @lc code=start
class Solution {
 public:
  bool used[10];
  int mp[26];

  bool isSolvable(vector<string>& ws, string s) {
    for (auto& w : ws) reverse(w.begin(), w.end());
    reverse(s.begin(), s.end());

    unordered_set<char> st;
    int max_len = 0;
    for (auto& w : ws) {
      if (w.size() > s.size()) return false;
      max_len = max(max_len, (int)w.size());
      st.insert(w.begin(), w.end());
    }
    st.insert(s.begin(), s.end());
    if (st.size() > 10 || max_len + 1 < s.size()) return false;
    memset(used, 0, sizeof used);
    memset(mp, -1, sizeof mp);
    return dfs(0, 0, 0, s, ws);
  }

  bool dfs(int k, int widx, int sum, string& s, vector<string>& ws) {
    if (k == s.size()) return !sum;
    for (int i = widx; i < ws.size(); i++) {
      auto& w = ws[i];
      if (k >= w.size()) continue;
      if (!~mp[w[k] - 'A']) {
        for (int j = 0; j < 10; j++) {
          if (!j && k == w.size() - 1 && w.size() > 1) continue;
          if (!used[j]) {
            used[j] = true;
            mp[w[k] - 'A'] = j;
            sum += j;
            if (dfs(k, i + 1, sum, s, ws)) return true;
            used[j] = false;
            mp[w[k] - 'A'] = -1;
            sum -= j;
          }
        }
        return false;
      } else if (!mp[w[k] - 'A'] && k == w.size() - 1 && w.size() > 1)
        return false;
      else
        sum += mp[w[k] - 'A'];
    }

    int t = sum % 10;
    if (k == s.size() - 1 && s.size() > 1 && (!mp[s[k] - 'A'] || !t))
      return false;
    if (!~mp[s[k] - 'A'] && !used[t]) {
      mp[s[k] - 'A'] = t;
      used[t] = true;
      if (dfs(k + 1, 0, sum / 10, s, ws)) return true;
      mp[s[k] - 'A'] = -1;
      used[t] = false;
    } else if (mp[s[k] - 'A'] == t)
      return dfs(k + 1, 0, sum / 10, s, ws);
    return false;
  }
};
// @lc code=end
