/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
 public:
  int maxLength(vector<string>& a) {
    vector<int> v;
    bool flag = false;
    for (auto& s : a) {
      int x = 0;
      for (char ch : s) {
        if (x >> (ch - 'a') & 1) {
          s = "";
          break;
        }
        x |= 1 << (ch - 'a');
      }
      v.push_back(s.size() ? x : 0);
    }
    int res = 0;
    dfs(0, 0, 0, v, a, res);
    return res;
  }

  void dfs(int u, int b, int len, vector<int>& v, vector<string>& a, int& res) {
    res = max(res, len);
    for (int i = u; i < v.size(); i++) {
      if (b & v[i]) continue;
      dfs(i + 1, b | v[i], len + a[i].size(), v, a, res);
    }
  }
};
// @lc code=end
