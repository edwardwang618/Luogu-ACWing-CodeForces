/*
 * @lc app=leetcode id=1096 lang=cpp
 *
 * [1096] Brace Expansion II
 */

// @lc code=start

class Solution {
 public:
  using SS = unordered_set<string>;

  SS add(SS& a, SS& b) {
    SS c = a;
    for (auto& x : b)
      if (x.size()) c.insert(x);
    return c;
  }

  SS mul(SS& a, SS& b) {
    SS c;
    for (auto& x : a)
      for (auto& y : b)
        if (x.size() || y.size()) c.insert(x + y);
    return c;
  }

  SS dfs(int& k, string& e) {
    SS a, b;
    b.insert("");
    while (k < e.size() && e[k] != '}') {
      bool is_add = true;
      SS c;
      if (e[k] == ',') {
        k++;
        continue;
      }
      if (!k || e[k - 1] != ',') is_add = false;
      if (e[k] == '{') {
        c = dfs(++k, e);
        k++;
      } else {
        string s;
        while (k < e.size() && 'a' <= e[k] && e[k] <= 'z') s += e[k++];
        c.insert(s);
      }
      is_add ? a = add(a, b), b = c : b = mul(b, c);
    }

    return add(a, b);
  }

  vector<string> braceExpansionII(string e) {
    int k = 0;
    auto v = dfs(k, e);
    vector<string> res(v.begin(), v.end());
    sort(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
