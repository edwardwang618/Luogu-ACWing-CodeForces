/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */

// @lc code=start
class MapSum {
public:
  struct Node {
    int ne[26];
    int cnt;
    Node() : ne{0}, cnt(0) {}
  };

  vector<Node> pl;
  unordered_map<string, int> mp;

  MapSum() { pl.emplace_back(); }

#define idx(ch) (ch - 'a')
#define child(u, k) pl[u].ne[k]

  void insert(const string &s, int x) {
    auto [it, ins] = mp.try_emplace(s, x);
    int old = ins ? 0 : it->second;
    if (!ins)
      it->second = x;
    int diff = x - old;

    int p = 0;
    for (char ch : s) {
      int idx = idx(ch), ne = child(p, idx);
      if (!ne) {
        child(p, idx) = ne = pl.size();
        pl.emplace_back();
      }
      p = child(p, idx);
      pl[p].cnt += diff;
    }
  }

  int sum(const string &pre) {
    int p = 0;
    for (char ch : pre) {
      int idx = idx(ch), ne = child(p, idx);
      if (!ne)
        return 0;
      p = child(p, idx);
    }
    return pl[p].cnt;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
