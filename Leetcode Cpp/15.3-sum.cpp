/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& a) {
    sort(a.begin(), a.end());
    vector<vector<int>> res;
    int n = a.size();
    for (int i = 0; i + 2 < n; i++) {
      int j = i + 1, k = n - 1;
      while (j < k) {
        if (a[j] + a[k] < -a[i]) j++;
        else if (a[j] + a[k] > -a[i]) k--;
        else {
          res.push_back({a[i], a[j], a[k]});
          while (j < k && a[j] == a[j + 1]) j++;
          j++;
          while (j < k && a[k] == a[k - 1]) k--;
          k--;
        }
      }

      while (i + 2 < n && a[i] == a[i + 1]) i++;
    }

    return res;
  }
};
// @lc code=end
