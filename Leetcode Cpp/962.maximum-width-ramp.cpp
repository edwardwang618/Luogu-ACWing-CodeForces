/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    int n = A.size(), stk[n], top = 0, res = 0;
    for (int i = 0; i < n; i++) {
      int pos = bin_search(top - 1, stk, A[i], A);
      if (~pos) res = max(res, i - pos);
      if (!top || A[stk[top - 1]] > A[i]) stk[top++] = i;
    }

    return res;
  }

  int bin_search(int r, int stk[], int x, vector<int>& A) {
    int l = 0;
    if (l > r) return -1;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (A[stk[mid]] <= x)
        r = mid;
      else
        l = mid + 1;
    }
    return A[stk[l]] <= x ? stk[l] : -1;
  }

  // int maxWidthRamp(vector<int>& A) {
  //   int n = A.size(), p[n];
  //   for (int i = 0; i < n; i++) p[i] = i;
  //   sort(p, p + n, [&](int i, int j) {
  //     if (A[i] != A[j])
  //       return A[i] < A[j];
  //     else
  //       return i < j;
  //   });

  //   int res = 0;
  //   for (int i = 0, j = n; i < n; i++) {
  //     j = min(j, p[i]);
  //     if (j < p[i]) res = max(res, p[i] - j);
  //   }

  //   return res;
  // }
};
// @lc code=end
