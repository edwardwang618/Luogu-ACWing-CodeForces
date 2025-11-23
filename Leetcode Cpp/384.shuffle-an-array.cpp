/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> c, a;
  Solution(vector<int>& a) { c = this->a = a; }

  vector<int> reset() { return a; }

  vector<int> shuffle() {
    int n = c.size();
    for (int i = n - 1; i >= 0; i--) swap(c[rand() % (i + 1)], c[i]);
    return c;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
