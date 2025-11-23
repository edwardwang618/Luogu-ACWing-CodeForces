/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 */

// @lc code=start
class Solution {
 public:
#define cross(x1, y1, x2, y2) (x1 * y2 - x2 * y1)

  int area(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
    int x1 = p2[0] - p1[0], y1 = p2[1] - p1[1];
    int x2 = p3[0] - p1[0], y2 = p3[1] - p1[1];
    return cross(x1, y1, x2, y2);
  }

  vector<vector<int>> outerTrees(vector<vector<int>>& vv) {
    sort(vv.begin(), vv.end());
    int n = vv.size();
    vector<int> stk;
    vector<bool> used(n);
    for (int i = 0; i < n; i++) {
      while (stk.size() >= 2 &&
             area(vv[stk[stk.size() - 2]], vv[stk.back()], vv[i]) > 0) {
        used[stk.back()] = false;
        stk.pop_back();
      }

      stk.push_back(i);
      used[i] = true;
    }

    used[0] = false;
    for (int i = n - 1; i >= 0; i--) {
      if (used[i]) continue;
      while (stk.size() >= 2 &&
             area(vv[stk[stk.size() - 2]], vv[stk.back()], vv[i]) > 0)
        stk.pop_back();

      stk.push_back(i);
    }

    vector<vector<int>> res;
    for (int i = 0; i < stk.size() - 1; i++) res.push_back(vv[stk[i]]);
    return res;
  }
};
// @lc code=end
