/*
 * @lc app=leetcode id=2349 lang=cpp
 *
 * [2349] Design a Number Container System
 */

// @lc code=start
class NumberContainers {
 public:
  unordered_map<int, set<int>> mp1;
  unordered_map<int, int> mp2;

  NumberContainers() {}

  void change(int idx, int x) {
    if (mp2.count(idx)) {
      int y = mp2[idx];
      mp1[y].erase(idx);
      if (mp1[y].empty()) mp1.erase(y);
    }

    mp2[idx] = x;
    mp1[x].insert(idx);
  }

  int find(int x) {
    if (!mp1.count(x)) return -1;
    return *mp1[x].begin();
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end
