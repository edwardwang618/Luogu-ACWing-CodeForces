/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution {
 public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    int n = books.size();
    vector<int> f(n + 1, 1e9);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
      int s = 0, h = 0;
      for (int j = i; j; j--) {
        s += books[j - 1][0];
        if (s > shelfWidth) break;
        h = max(h, books[j - 1][1]);
        f[i] = min(f[i], f[j - 1] + h);
      }
    }

    return f[n];
  }
};
// @lc code=end
