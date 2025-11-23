/*
 * @lc app=leetcode id=1298 lang=cpp
 *
 * [1298] Maximum Candies You Can Get from Boxes
 */

// @lc code=start
class Solution {
 public:
  int maxCandies(vector<int>& status, vector<int>& candies,
                 vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                 vector<int>& initialBoxes) {
    unordered_set<int> s_open, s_closed, s_keys;
    for (int x : initialBoxes) {
      if (status[x]) s_open.insert(x);
      else s_closed.insert(x);
    }

    int res = 0;
    while (s_open.size()) {
      auto it = s_open.begin();
      int x = *it;
      s_open.erase(it);
      res += candies[x];
      for (int k : keys[x]) {
        if (s_closed.count(k)) {
          s_open.insert(k);
          s_closed.erase(k);
        } else s_keys.insert(k);
      }

      for (int y : containedBoxes[x]) {
        if (status[y]) s_open.insert(y);
        else if (s_keys.count(y)) {
          s_open.insert(y);
          s_keys.erase(y);
        } else s_closed.insert(y);
      }
    }
    
    return res;
  }
};
// @lc code=end
