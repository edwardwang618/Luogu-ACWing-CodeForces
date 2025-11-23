/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
    int n = v1.size() + v2.size();
    if (n % 2)
      return find(v1, 0, v2, 0, n / 2 + 1);
    else
      return (find(v1, 0, v2, 0, n / 2) + find(v1, 0, v2, 0, n / 2 + 1)) / 2.0;
  }

  int find(vector<int>& v1, int i, vector<int>& v2, int j, int k) {
    if (v1.size() - i > v2.size() - j) return find(v2, j, v1, i, k);
    if (v1.size() == i) return v2[j + k - 1];
    if (k == 1) return v1.size() == i ? v2[j] : min(v1[i], v2[j]);
    int k1 = min((int)v1.size() - 1, i + k / 2 - 1),
        k2 = j + k - (k1 - i + 1) - 1;
    if (v1[k1] < v2[k2])
      return find(v1, k1 + 1, v2, j, k - (k1 - i + 1));
    else if (v1[k1] > v2[k2])
      return find(v1, i, v2, k2 + 1, k - (k2 - j + 1));
    else
      return v1[k1];
  }
};
// @lc code=end
