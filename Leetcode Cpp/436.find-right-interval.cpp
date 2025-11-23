/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& a) {
    int n = a.size();
    vector<int> res(n, -1);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[a[i][0]] = i;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      int l = i, r = n - 1;
      if (l > r) continue;
      while (l < r) {
        int mid = l + (r - l >> 1);
        if (a[mid][0] >= a[i][1]) r = mid;
        else l = mid + 1;
      }
      if (a[l][0] >= a[i][1]) res[mp[a[i][0]]] = mp[a[l][0]];
    }

    return res;
  }
};
// @lc code=end
