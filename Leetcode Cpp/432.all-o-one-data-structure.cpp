/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
class AllOne {
  struct Block {
    int freq;
    unordered_set<string> keys;
  };
  // From front to back, freq increasing;
  // No block is empty;
  // mp maps the key to It which refers to the Block it belongs to
  list<Block> blocks;
  using It = list<Block>::iterator;
  unordered_map<string, It> mp;

  auto ensure_after(It it, int freq) {
    auto ne = next(it);
    if (ne == blocks.end() || ne->freq != freq)
      ne = blocks.insert(ne, {freq, {}});
    return ne;
  }

  auto ensure_before(It it, int freq) {
    if (it == blocks.begin())
      return blocks.insert(it, {freq, {}});
    auto pr = prev(it);
    if (pr->freq != freq)
      pr = blocks.insert(it, {freq, {}});
    return pr;
  }

  // Ensure key is in it->keys
  void remove_key_and_cleanup(It it, const string &key) {
    if (it->keys.size() == 1)
      blocks.erase(it);
    else
      it->keys.erase(key);
  }

public:
  AllOne() {}

  void inc(const string &key) {
    auto it = mp.find(key);
    if (it == mp.end()) {
      // new key, guarantee blocks begin with freq 1
      if (blocks.empty() || blocks.begin()->freq != 1)
        blocks.insert(blocks.begin(), {1, {}});
      blocks.begin()->keys.insert(key);
      mp.emplace(key, blocks.begin());
      return;
    }
    // existing key
    auto block_it = it->second;
    auto ne_block_it = ensure_after(block_it, block_it->freq + 1);
    ne_block_it->keys.insert(key);
    remove_key_and_cleanup(block_it, key);
    it->second = ne_block_it;
  }

  void dec(const string &key) {
    auto it = mp.find(key);
    auto block_it = it->second;
    if (block_it->freq == 1) {
      mp.erase(it);
      remove_key_and_cleanup(block_it, key);
      return;
    }
    auto pr_block_it = ensure_before(block_it, block_it->freq - 1);
    pr_block_it->keys.insert(key);
    remove_key_and_cleanup(block_it, key);
    it->second = pr_block_it;
  }

  string getMaxKey() {
    if (blocks.empty())
      return "";
    return *blocks.back().keys.begin();
  }

  string getMinKey() {
    if (blocks.empty())
      return "";
    return *blocks.front().keys.begin();
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
