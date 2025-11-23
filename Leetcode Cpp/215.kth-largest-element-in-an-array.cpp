/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
 public:
  int findKthLargest(vector<int>& A, int k) {
    int n = A.size();
    k = n - k;
    return quick_select(A, 0, n - 1, k);
  }

  int quick_select(vector<int>& A, int l, int r, int k) {
    while (l < r) {
      int i = l, j = r, piv = A[l + (r - l >> 1)];
      while (i <= j) {
        while (A[i] < piv) i++;
        while (A[j] > piv) j--;
        if (i <= j) swap(A[i++], A[j--]);
      }

      if (k <= j)
        r = j;
      else if (k >= i)
        l = i;
      else
        break;
    }
    return A[k];
  }
};
// @lc code=end
