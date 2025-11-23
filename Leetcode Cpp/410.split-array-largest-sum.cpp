/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
 public:
  // int splitArray(vector<int>& A, int k) {
  //   int l = 0, r = 0;
  //   for (int x : A) l = max(l, x), r += x;
  //   while (l < r) {
  //     int mid = l + (r - l >> 1);
  //     if (check(A, k, mid)) r = mid;
  //     else l = mid + 1;
  //   }

  //   return l;
  // }

  // bool check(vector<int>& A, int k, int sum) {
  //   int cnt = 1, ksum = 0;
  //   for (auto x : A) {
  //     if (ksum + x <= sum) ksum += x;
  //     else cnt++, ksum = x;

  //     if (cnt > k) return false;
  //   }

  //   return cnt <= k;
  // }

  int splitArray(vector<int>& A, int k) {
    int n = A.size();
    int f[k + 1][n];
    for (int i = 0; i < n; i++) {
      f[1][i] = A[i];
      if (i) f[1][i] += f[1][i - 1];
    }

    for (int i = 2; i <= k; i++)
      for (int j = i - 1; j < n; j++) {
        int sum = 0;
        f[i][j] = INT_MAX;
        for (int l = j; l >= i - 1; l--) {
          sum += A[l];
          f[i][j] = min(f[i][j], max(f[i - 1][l - 1], sum));
          if (sum >= f[i - 1][l - 1]) break;
        }
      }

    return f[k][n - 1];
  }
};
// @lc code=end
