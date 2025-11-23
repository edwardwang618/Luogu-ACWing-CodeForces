/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
 public:
  vector<int> intersect(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> mp;
    for (int x : a) mp[x]++;
    vector<int> res;
    for (int x : b) {
      if (!mp.count(x)) continue;
      if (!--mp[x]) mp.erase(x);
      res.push_back(x);
    }

    return res;
  }
};
// @lc code=end
