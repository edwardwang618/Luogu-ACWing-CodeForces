/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
class Solution {
 public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> res(num_people, 0);
    for (int idx = 0; candies > 0; idx++) {
      res[idx % num_people] += min(candies, idx + 1);
      candies -= idx + 1;
    }

    return res;
  }
};
// @lc code=end
