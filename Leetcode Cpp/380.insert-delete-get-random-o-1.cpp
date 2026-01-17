/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
 public:
  vector<int> v;
  unordered_map<int, int> mp;
  RandomizedSet() {}

  bool insert(int x) {
    auto [it, ins] = mp.emplace(x, v.size());
    if (!ins) return false;
    v.push_back(x);
    return true;
  }

  bool remove(int x) {
    auto it = mp.find(x);
    if (it == mp.end()) return false;
    int idx = it->second;
    swap(v[idx], v.back());
    mp[v[idx]] = idx;
    v.pop_back();
    mp.erase(it);
    return true;
  }

  int getRandom() { return v[rand() % v.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
