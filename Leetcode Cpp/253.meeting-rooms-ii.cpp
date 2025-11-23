/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */

// @lc code=start
class Solution {
 public:
  // int minMeetingRooms(vector<vector<int>>& is) {
  //   sort(is.begin(), is.end());
  //   auto cmp = [](auto& p1, auto& p2) { return p1[1] > p2[1]; };
  //   priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
  //   for (auto& ii : is) {
  //     if (heap.size() && heap.top()[1] <= ii[0]) heap.pop();
  //     heap.push(ii);
  //   }

  //   return heap.size();
  // }

  int minMeetingRooms(vector<vector<int>>& is) {
    map<int, int> mp;
    for (auto& p : is) mp[p[0]]++, mp[p[1]]--;
    int res = 0, cnt = 0;
    for (auto &[k, v] : mp) cnt += v, res = max(res, cnt);
    return res;
  }
};
// @lc code=end
