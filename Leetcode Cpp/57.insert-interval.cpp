/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& is, vector<int>& ni) {
    if (is.empty()) return {ni};

    vector<vector<int>> res;
    int i = 0;

    // 处理第一类区间
    for (; i < is.size() && is[i][1] < ni[0]; i++) res.push_back(is[i]);

    // 处理有交集的区间
    for (; i < is.size() && is[i][0] <= ni[1]; i++) {
      ni[0] = min(ni[0], is[i][0]);
      ni[1] = max(ni[1], is[i][1]);
    }
    // 将合并后的新区间加入结果中
    res.push_back(ni);

    // 处理剩下的区间
    for (; i < is.size(); i++) res.push_back(is[i]);
    return res;
  }
};
// @lc code=end
