/*
 * @lc app=leetcode id=1902 lang=cpp
 *
 * [1902] Depth of BST Given Insertion Order
 */

// @lc code=start
class Solution {
public:
  int maxDepthBST(vector<int> &order) {
    map<int, int> mp;
    int res = 0;
    for (int x : order) {
      auto [it, _] = mp.emplace(x, 0);
      int dep = 0;
      if (it != mp.begin()) dep = max(dep, prev(it)->second);
      if (next(it) != mp.end()) dep = max(dep, next(it)->second);
      it->second = dep + 1;
      res = max(res, dep + 1);
    }
    return res;
  }
};
// @lc code=end
