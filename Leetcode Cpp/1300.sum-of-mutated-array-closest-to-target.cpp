/*
 * @lc app=leetcode id=1300 lang=cpp
 *
 * [1300] Sum of Mutated Array Closest to Target
 */

// @lc code=start
class Solution {
 public:
  int findBestValue(vector<int>& A, int t) {
    sort(A.begin(), A.end());
    int n = A.size();
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + A[i - 1];
    int l = 0, r = A[n - 1];
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      int pos = bin_search(A, mid), sum = pre[pos + 1] + mid * (n - 1 - pos);
      if (sum <= t) l = mid;
      else r = mid - 1;
    }

    int pos, sum1, sum2;
    pos = bin_search(A, l), sum1 = pre[pos + 1] + l * (n - 1 - pos);
    pos = bin_search(A, l + 1), sum2 = pre[pos + 1] + (l + 1) * (n - 1 - pos);
    return abs(t - sum1) <= abs(sum2 - t) ? l : l + 1;
  }

  int bin_search(vector<int>& A, int x) {
    int l = 0, r = A.size() - 1;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (A[mid] <= x) l = mid;
      else r = mid - 1;
    }

    return A[l] <= x ? l : -1;
  }
};
// @lc code=end

