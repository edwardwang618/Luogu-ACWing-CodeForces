/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
class Solution {
 public:
  int countVowelPermutation(int n) {
    const int MOD = 1e9 + 7;
    vector<vector<int>> f(5, vector<int>(n + 1));
    for (int i = 0; i < 5; i++) f[i][1] = 1;
    vector<int> g[5] = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};
    for (int i = 2; i <= n; i++)
      for (int j = 0; j < 5; j++)
        for (int ne : g[j]) f[ne][i] = (f[ne][i] + f[j][i - 1]) % MOD;

    int res = 0;
    for (int i = 0; i < 5; i++) res = (res + f[i][n]) % MOD;
    return res;
  }
};
// @lc code=end
