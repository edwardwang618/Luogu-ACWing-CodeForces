/*
 * @lc app=leetcode id=1196 lang=cpp
 *
 * [1196] How Many Apples Can You Put into the Basket
 */

// @lc code=start
class Solution {
 public:
  int maxNumberOfApples(vector<int>& weight) {
    int res = 0, x = 5000;
    sort(weight.begin(), weight.end());
    for (int y : weight) 
      if (x >= y) {
        x -= y;
        res++;
      } else break;
    
    return res;
  }
};
// @lc code=end
