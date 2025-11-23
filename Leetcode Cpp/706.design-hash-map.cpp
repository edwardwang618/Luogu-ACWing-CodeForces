/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
 public:
  using PII = pair<int, int>;
#define x first
#define y second
#define N 19997
  vector<PII> h[N];
  MyHashMap() {}

  void put(int key, int value) {
    int ha = key % N;
    for (auto &[k, v] : h[ha])
      if (k == key) {
        v = value;
        return;
      }
    h[ha].emplace_back(key, value);
  }

  int get(int key) {
    int ha = key % N;
    for (auto &[k, v] : h[ha]) {
      if (k == key) return v;
    }

    return -1;
  }

  void remove(int key) {
    int ha = key % N;
    for (auto it = h[ha].begin(); it != h[ha].end(); it++)
      if (it->x == key) {
        h[ha].erase(it);
        return;
      }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
