/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
 public:
#define N 19997
  vector<int> h[N];
  MyHashSet() {}

  void add(int key) {
    int ha = key % N;
    for (int x : h[ha])
      if (x == key) return;
    h[ha].push_back(key);
  }

  void remove(int key) {
    int ha = key % N;
    for (auto it = h[ha].begin(); it != h[ha].end(); it++)
      if (*it == key) {
        h[ha].erase(it);
        return;
      }
  }

  bool contains(int key) {
    int ha = key % N;
    for (int x : h[ha])
      if (x == key) return true;
    return false;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
