/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 */

// @lc code=start
class Solution {
 public:
  int n, len;
  unordered_map<int, int> mp;
  Solution(int n, vector<int>& blacklist) {
    this->n = n;
    len = blacklist.size();
    unordered_set<int> st;
    for (int i = n - len; i < n; i++) st.insert(i);
    for (int i : blacklist) st.erase(i);
    auto it = st.begin();
    for (int i : blacklist)
      if (i < n - len) mp[i] = *it++;
  }

  int pick() {
    int k = rand() % (n - len);
    if (mp.count(k)) return mp[k];
    return k;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end
