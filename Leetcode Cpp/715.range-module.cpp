/*
 * @lc app=leetcode id=715 lang=cpp
 *
 * [715] Range Module
 */

// @lc code=start
class RangeModule {
 public:
  struct Node {
    int lc, rc;
    int l, r;
    // 当前区间track了没
    bool mark;
    // 懒标记，0表示无标记，1表示track了，-1表示未track
    int tag;
  };
  vector<Node> tr;

  int new_node(int l, int r) {
    tr.push_back({0, 0, l, r});
    return tr.size() - 1;
  }

  void pushup(int u) { tr[u].mark = tr[tr[u].lc].mark && tr[tr[u].rc].mark; }

  void pushdown(int u) {
    Node &lc = tr[tr[u].lc], &rc = tr[tr[u].rc];
    if (tr[u].tag) {
      lc.mark = rc.mark = tr[u].tag == 1;
      lc.tag = rc.tag = tr[u].tag;
      tr[u].tag = 0;
    }
  }

  void split(int u) {
    if (tr[u].lc) return;
    int mid = tr[u].l + tr[u].r >> 1;
    tr[u].lc = new_node(tr[u].l, mid);
    tr[u].rc = new_node(mid + 1, tr[u].r);
  }

  void add(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
      tr[u].mark = true;
      tr[u].tag = 1;
      return;
    }

    split(u);
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) add(tr[u].lc, l, r);
    if (r > mid) add(tr[u].rc, l, r);
    pushup(u);
  }

  void remove(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
      tr[u].mark = false;
      tr[u].tag = -1;
      return;
    }

    split(u);
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) remove(tr[u].lc, l, r);
    if (r > mid) remove(tr[u].rc, l, r);
    pushup(u);
  }

  bool query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
      return tr[u].mark;
    }

    split(u);
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid && !query(tr[u].lc, l, r)) return false;
    if (r > mid && !query(tr[u].rc, l, r)) return false;
    return true;
  }

  RangeModule() {
    tr.push_back({});
    new_node(1, (int)1e9);
  }

  void addRange(int left, int right) { add(1, left, right - 1); }

  bool queryRange(int left, int right) { return query(1, left, right - 1); }

  void removeRange(int left, int right) { remove(1, left, right - 1); }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end
