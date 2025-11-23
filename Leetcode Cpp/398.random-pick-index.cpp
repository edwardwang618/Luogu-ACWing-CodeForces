/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
class Solution {
 public:
  // unordered_map<int, vector<int>> mp;
  // Solution(vector<int>& a) {
  //   srand(time(nullptr));
  //   for (int i = 0; i < a.size(); i++) mp[a[i]].push_back(i);
  // }

  // int pick(int x) {
  //   auto& v = mp[x];
  //   return v[rand() % v.size()];
  // }

  vector<int> a;
  Solution(vector<int>& nums) { a = nums; }

  int pick(int x) {
    int cnt = 0, idx = 0;
    for (int i = 0; i < a.size(); i++)
      if (a[i] == x) {
        cnt++;
        if (rand() % cnt == 0) idx = i;
      }
    return idx;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
