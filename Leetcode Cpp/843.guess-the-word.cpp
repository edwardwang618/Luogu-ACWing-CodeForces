/*
 * @lc app=leetcode id=843 lang=cpp
 *
 * [843] Guess the Word
 */

// @lc code=start
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
  void findSecretWord(vector<string> &ws, Master &master) {
    int n = ws.size();
    vector<vector<int>> f(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < 6; k++)
          if (ws[i][k] == ws[j][k]) f[i][j]++;
    
    vector<bool> used(n);
    for (int _ = 0; _ < 30; _++) {
      int k = -1, w = INT_MAX;
      vector<int> best;
      for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        int cnt[7]{};
        for (int j = 0; j < n; j++) {    
          if (used[j]) continue;
          cnt[f[i][j]]++;
        }
        int t = 0;
        for (int j = 0; j < 7; j++) t = max(t, cnt[j]);
        if (w > t) {
          w = t;
          k = i;
        }
      }

      int cnt = master.guess(ws[k]);
      if (cnt == 6) return;
      used[k] = true;
      for (int i = 0; i < n; i++)
        if (!used[i] && f[i][k] != cnt) used[i] = true;
    }
  }
};
// @lc code=end
