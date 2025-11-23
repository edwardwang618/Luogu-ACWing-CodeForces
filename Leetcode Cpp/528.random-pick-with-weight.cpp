/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
 public:
  vector<int> p;

  Solution(vector<int>& w) {
    srand(time(nullptr));
    p.resize(w.size());
    p[0] = w[0];
    for (int i = 1; i < w.size(); i++)
      p[i] = p[i - 1] + w[i];
  }

  int pickIndex() {
    int idx = rand() % p.back();
    int l = 0, r = p.size() - 1;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (p[mid] > idx) r = mid;
      else l = mid + 1;
    }
    return l;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
