/*
 * @lc app=leetcode id=1756 lang=cpp
 *
 * [1756] Design Most Recently Used Queue
 */

// @lc code=start
class MRUQueue {
  struct Node {
    int l, r;
    int key, val;
    int sz;
    Node(int x) : l(0), r(0), key(x), val(rand()), sz(1) {}
  };
  vector<Node> tr;
  int root;
  int new_node(int x) {
    int n = tr.size();
    tr.emplace_back(x);
    return n;
  }

#define l(p) tr[p].l
#define r(p) tr[p].r
#define key(p) tr[p].key
#define val(p) tr[p].val
#define sz(p) tr[p].sz

  void pushup(int p) { sz(p) = sz(l(p)) + sz(r(p)) + 1; }
  int merge(int x, int y) {
    if (!x || !y)
      return x ^ y;
    if (val(x) > val(y)) {
      r(x) = merge(r(x), y);
      pushup(x);
      return x;
    } else {
      l(y) = merge(x, l(y));
      pushup(y);
      return y;
    }
  }
  void split(int p, int sz, int &x, int &y) {
    if (!p)
      x = y = 0;
    else {
      if (sz(l(p)) < sz) {
        x = p;
        split(r(p), sz - sz(l(p)) - 1, r(p), y);
      } else {
        y = p;
        split(l(p), sz, x, l(p));
      }
      pushup(p);
    }
  }

public:
  MRUQueue(int n) {
    tr.reserve(n + 1);
    // null is 0
    tr.emplace_back(0);
    tr[0].sz = 0;

    root = 0;
    for (int i = 1; i <= n; i++)
      root = merge(root, new_node(i));
  }

  int fetch(int k) {
    int x, y, z;
    split(root, k, x, z);
    split(x, k - 1, x, y);
    int res = key(y);
    root = merge(merge(x, z), y);
    return res;
  }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
// @lc code=end
