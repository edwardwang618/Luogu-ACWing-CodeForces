/*
 * @lc app=leetcode id=1177 lang=cpp
 *
 * [1177] Can Make Palindrome from Substring
 */

// @lc code=start
class Solution {
 public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>> &qs) {
    int n = s.size();
    vector<vector<int>> f(26, vector<int>(n + 1));
    for (int i = 0; i < n; i++) f[s[i] - 'a'][i + 1]++;

    for (auto &v : f)
      for (int i = 1; i <= n; i++) v[i] += v[i - 1];

    vector<bool> res(qs.size());
    for (int i = 0; i < qs.size(); i++) {
      auto &q = qs[i];
      int l = q[0], r = q[1], k = q[2], cnt = 0;
      for (auto &v : f)
        if ((v[r + 1] - v[l]) % 2) cnt++;

      res[i] = cnt / 2 <= k;
    }

    return res;
  }
};
// @lc code=end
