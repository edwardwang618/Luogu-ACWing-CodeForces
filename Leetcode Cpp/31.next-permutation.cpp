/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
 public:
  void nextPermutation(vector<int>& a) {
    int n = a.size(), i = n - 1;
    while (i && a[i - 1] >= a[i]) i--;
    if (!i) {
      reverse(a.begin(), a.end());
      return;
    }

    auto f = [&](int l, int r, int x) {
      while (l < r) {
        int mid = l + r + 1 >> 1;
        if (a[mid] > x) l = mid;
        else r = mid - 1;
      }
      return l;
    };

    int idx = f(i, n - 1, a[i - 1]);
    swap(a[idx], a[i - 1]);
    reverse(a.begin() + i, a.end());
  }
};
// @lc code=end
