/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
class RandomizedCollection {
public:
  vector<int> v;
  unordered_map<int, unordered_set<int>> mp;

  RandomizedCollection() {}

  bool insert(int x) {
    auto [it, ins] = mp.try_emplace(x);
    v.push_back(x);
    it->second.insert(v.size() - 1);
    return ins;
  }

  bool remove(int x) {
    auto it = mp.find(x);
    if (it == mp.end()) return false;
    auto &pos_set = it->second;
    if (x == v.back()) {
      pos_set.erase(v.size() - 1);
      v.pop_back();
      if (pos_set.empty()) mp.erase(it);
    } else {
      int pos = *pos_set.begin();
      pos_set.erase(pos_set.begin());
      if (pos_set.empty()) mp.erase(it);
      int last = v.back();
      auto it_last = mp.find(last);
      it_last->second.erase(v.size() - 1);
      it_last->second.insert(pos);
      v[pos] = last;
      v.pop_back();
    }
    return true;
  }

  int getRandom() {
    return v[rand() % v.size()];
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
