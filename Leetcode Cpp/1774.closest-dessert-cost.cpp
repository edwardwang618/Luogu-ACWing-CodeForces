/*
 * @lc app=leetcode id=1774 lang=cpp
 *
 * [1774] Closest Dessert Cost
 */

// @lc code=start
class Solution {
 public:
  int closestCost(vector<int>& a, vector<int>& top, int t) {
    int n = a.size(), m = top.size();
    vector<int> b;
    for (int j = 0; j < 1 << m * 2; j++) {
      int cost = 0;
      bool valid = true;
      for (int k = 0; k < m; k++) {
        int cnt = j >> k * 2 & 3;
        if (cnt > 2) {
          valid = false;
          break;
        }
        cost += cnt * top[k];
      }

      if (!valid) continue;
      b.push_back(cost);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = INT_MAX;
    for (int i = 0, j = b.size() - 1; i < n && j >= 0;) {
      int x = a[i] + b[j];
      if (abs(x - t) < abs(res - t) || abs(x - t) == abs(res - t) && x < res)
        res = x;
      if (a[i] + b[j] > t)
        j--;
      else if (a[i] + b[j] < t)
        i++;
      else
        break;
    }

    return res;
  }
};
// @lc code=end
