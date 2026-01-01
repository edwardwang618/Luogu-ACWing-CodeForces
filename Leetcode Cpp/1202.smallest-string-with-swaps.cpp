/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
class Solution {
public:
  string smallestStringWithSwaps(string &s, vector<vector<int>> &ps) {
    int n = s.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    for (auto &v : ps) {
      int a = v[0], b = v[1];
      int pa = find(a), pb = find(b);
      if (pa != pb) p[pa] = pb;
    };

    unordered_map<int, string> mp;
    for (int i = 0; i < n; i++) mp[find(i)].push_back(s[i]);
    for (auto &[k, v] : mp)
      sort(v.begin(), v.end(), [&](char i, char j) {
        return i > j;
      });
    
    for (int i = 0; i < n; i++) {
      auto &v = mp[find(i)];
      s[i] = v.back();
      v.pop_back();
    }
    return s;
  }
};
// @lc code=end
