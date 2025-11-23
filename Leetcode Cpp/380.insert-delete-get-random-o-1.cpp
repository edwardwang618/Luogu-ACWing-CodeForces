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
    if (mp.count(x)) return false;
    v.push_back(x);
    mp[x] = v.size() - 1;
    return true;
  }

  bool remove(int x) {
    if (!mp.count(x)) return false;
    int idx = mp[x];
    swap(v[idx], v.back());
    mp[v[idx]] = idx;
    v.pop_back();
    mp.erase(x);
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
