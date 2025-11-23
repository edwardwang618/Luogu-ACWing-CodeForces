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
    // 找到第一个使得a[i - 1] < a[i]的i
    while (i > 0 && a[i - 1] >= a[i]) i--;
    // 如果没找到，说明原数组逆序，翻转之后返回
    if (!i) {
      reverse(a.begin(), a.end());
      return;
    }

    auto bin_search = [&](int l, int r, int x) {
      while (l < r) {
        int mid = l + (r - l + 1 >> 1);
        if (a[mid] > x)
          l = mid;
        else
          r = mid - 1;
      }
      return l;
    };

    // 找到a[i, ..., len - 1]中大于a[i - 1]的最小的数的下标。
    // 由于这段数组递减，所以可以用二分
    int idx = bin_search(i, a.size() - 1, a[i - 1]);
    // 交换后翻转
    swap(a[i - 1], a[idx]);
    reverse(a.begin() + i, a.end());
  }
};
// @lc code=end
