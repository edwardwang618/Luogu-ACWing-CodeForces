/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortArray(vector<int>& a) {
    vector<int> tmp(a.size());
    merge_sort(0, a.size() - 1, a, tmp);
    return a;
  }

  void merge_sort(int l, int r, vector<int>& a, vector<int>& tmp) {
    if (l >= r) return;
    int mid = l + (r - l >> 1);
    merge_sort(l, mid, a, tmp), merge_sort(mid + 1, r, a, tmp);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
      if (a[i] <= a[j])
        tmp[k++] = a[i++];
      else
        tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = tmp[i];
  }
};
// @lc code=end
