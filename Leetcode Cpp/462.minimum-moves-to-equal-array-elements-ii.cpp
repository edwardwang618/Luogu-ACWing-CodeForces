/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution {
public:
  int minMoves2(vector<int> &a) {
    auto quick_select = [&](int l, int r, int k) {
      while (l < r) {
        int i = l, j = r, piv = a[l + r >> 1];
        while (i <= j) {
          while (a[i] < piv) i++;
          while (a[j] > piv) j--;
          if (i <= j) swap(a[i++], a[j--]);
        }
        if (k <= j) r = j;
        else if (k >= i) l = i;
        else break;
      }
      return a[k];
    };
    int n = a.size();
    int x = quick_select(0, n - 1, n / 2);
    int res = 0;
    for (int y : a) res += abs(y - x);
    return res;
  }
};
// @lc code=end
