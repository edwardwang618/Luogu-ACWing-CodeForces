/*
 * @lc app=leetcode id=1257 lang=cpp
 *
 * [1257] Smallest Common Region
 */

// @lc code=start
class Solution {
public:
  string findSmallestRegion(vector<vector<string>> &rs, string &r1,
                            string &r2) {
    unordered_map<string, string> fa;
    for (auto &v : rs)
      for (int i = 1; i < v.size(); i++)
        fa[v[i]] = v[0];

    auto step = [&](string &t) {
      int res = 0;
      string s = t;
      for (auto it = fa.find(s); it != fa.end(); it = fa.find(s)) {
        res++;
        s = it->second;
      }
      return res;
    };

    int s1 = step(r1), s2 = step(r2);
    if (s1 < s2) {
      swap(s1, s2);
      swap(r1, r2);
    }
    for (int d = s1 - s2; d; d--)
      r1 = fa[r1];
    while (r1 != r2)
      r1 = fa[r1], r2 = fa[r2];
    return r1;
  }
};
// @lc code=end
