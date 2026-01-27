/*
 * @lc app=leetcode id=1993 lang=cpp
 *
 * [1993] Operations on Tree
 */

// @lc code=start
class LockingTree {
  int n;
  vector<int> p;
  vector<vector<int>> children;
  vector<int> locked;

public:
  LockingTree(vector<int> &p) : p(p) {
    n = p.size();
    children.resize(n);
    locked.assign(n, -1);
    for (int i = 1; i < n; i++) {
      children[p[i]].push_back(i);
    }
  }

  bool lock(int x, int user) {
    if (~locked[x])
      return false;
    locked[x] = user;
    return true;
  }

  bool unlock(int x, int user) {
    if (locked[x] != user)
      return false;
    locked[x] = -1;
    return true;
  }

  bool upgrade(int x, int user) {
    if (~locked[x])
      return false;

    for (int y = p[x]; ~y; y = p[y])
      if (~locked[y])
        return false;

    bool hasLocked = false;
    auto dfs = [&](this auto &&dfs, int u) -> void {
      if (~locked[u]) {
        hasLocked = true;
        locked[u] = -1;
      }
      for (int v : children[u])
        dfs(v);
    };
    dfs(x);

    if (!hasLocked)
      return false;

    locked[x] = user;
    return true;
  }
};
/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end
