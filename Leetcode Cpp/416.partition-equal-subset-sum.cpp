/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
  bool canPartition(vector<int> &a) {
    int n = a.size();
    int sum = 0;
    for (int x : a) sum += x;
    if (sum & 1) return false;
    sum /= 2;
    vector<bool> f(sum + 1);
    f[0] = true;
    for (int i = 1; i <= n; i++) {
      for (int j = sum; j >= a[i - 1]; j--) 
        f[j] = f[j] || f[j - a[i - 1]];
      if (f[sum]) return true;
    }
    return false;
  }
};
// @lc code=end
