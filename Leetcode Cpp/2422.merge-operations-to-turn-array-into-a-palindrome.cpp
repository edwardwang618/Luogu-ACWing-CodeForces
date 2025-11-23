/*
 * @lc app=leetcode id=2422 lang=cpp
 *
 * [2422] Merge Operations to Turn Array Into a Palindrome
 */

// @lc code=start
class Solution {
 public:
  int minimumOperations(vector<int>& a) {
    int n = a.size(), res = 0;
    long lsum = a[0], rsum = a.back();
    for (int i = 0, j = n - 1; i < j;)
      if (lsum < rsum) {
        i++;
        lsum += a[i];
        res++;
      } else if (lsum > rsum) {
        j--;
        rsum += a[j];
        res++;
      } else {
        i++, j--;
        lsum = a[i], rsum = a[j];
      }

    return res;
  }
};
// @lc code=end
