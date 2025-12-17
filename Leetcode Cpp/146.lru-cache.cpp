/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
  struct Node {
    int prev, next;
    int key, val;
    Node(int prev, int next, int key, int val)
        : prev(prev), next(next), key(key), val(val) {}
  };

#define head 0
#define tail 1
#define null -1
#define key(node_idx) pl[node_idx].key
#define val(node_idx) pl[node_idx].val
#define prev(node_idx) pl[node_idx].prev
#define next(node_idx) pl[node_idx].next

  vector<Node> pl;
  unordered_map<int, int> mp;
  int sz, cap;

  LRUCache(int capacity) : sz(0), cap(capacity) {
    pl.reserve(2 + cap);
    pl.emplace_back(null, tail, 0, 0);
    pl.emplace_back(head, null, 0, 0);
    mp.reserve(cap);
  }

  int new_node(int key, int val) {
    pl.emplace_back(null, null, key, val);
    return pl.size() - 1;
  }

  void move_to_head(int idx) {
    if (~prev(idx))
      next(prev(idx)) = next(idx);
    if (~next(idx))
      prev(next(idx)) = prev(idx);
    prev(idx) = head;
    next(idx) = next(head);
    next(head) = prev(next(idx)) = idx;
  }

  int get(int key) {
    auto it = mp.find(key);
    if (it == mp.end())
      return -1;
    int idx = it->second;
    move_to_head(idx);
    return val(idx);
  }

  void put(int key, int val) {
    auto it = mp.find(key);
    if (it != mp.end()) {
      // found
      int idx = it->second;
      val(idx) = val;
      move_to_head(idx);
    } else {
      // not found
      if (sz == cap) [[unlikely]] {
        if (!sz)
          return;
        int idx = pl[tail].prev;
        move_to_head(idx);
        mp.erase(key(idx));
        mp[key] = idx;
        key(idx) = key;
        val(idx) = val;
        return;
      }
      int idx = new_node(key, val);
      mp[key] = idx;
      move_to_head(idx);
      sz++;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
