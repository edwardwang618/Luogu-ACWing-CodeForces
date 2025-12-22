/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
public:
  using ull = unsigned long long;
  vector<string> wordBreak(string &s, vector<string> &ws) {
    static constexpr ull P = 131;
    unordered_set<ull> st;
    st.reserve(ws.size());
    int min_len = 2e9, max_len = 0;
    for (auto &s : ws) {
      min_len = min(min_len, (int)s.size());
      max_len = max(max_len, (int)s.size());
      ull h = 0;
      for (char ch : s)
        h = h * P + ch;
      st.insert(h);
    }

    int n = s.size();
    vector<ull> ha(n + 1), pow(n + 1);
    pow[0] = 1;
    for (int i = 0; i < n; i++) {
      ha[i + 1] = ha[i] * P + s[i];
      pow[i + 1] = pow[i] * P;
    }

    auto get_hash = [&](int l, int r) {
      return ha[r + 1] - ha[l] * pow[r - l + 1];
    };
    vector<bool> f(n + 1);
    f[n] = true;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        int len = j - i + 1;
        if (min_len <= len && len <= max_len && st.count(get_hash(i, j))) {
          if (f[i] = f[j + 1])
            break;
        }
      }
    }

    vector<string> res;
    auto dfs = [&](auto &&self, int u, string &p) -> void {
      if (u == n) {
        res.push_back(p.substr(0, p.size() - 1));
        return;
      }

      for (int i = u; i < n; i++)
        if (st.count(get_hash(u, i)) && f[i + 1]) {
          p += s.substr(u, i - u + 1) + " ";
          self(self, i + 1, p);
          p.resize(p.size() - (i - u + 2));
        }
    };
    string p;
    dfs(dfs, 0, p);
    return res;
  }
};
// @lc code=end
