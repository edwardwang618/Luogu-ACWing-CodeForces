/*
 * @lc app=leetcode id=2276 lang=cpp
 *
 * [2276] Count Integers in Intervals
 */

// @lc code=start

class CountIntervals {
 public:
  struct Node {
    int st, ed, x;
    Node *l, *r;
    Node(int st, int ed, int x)
        : st(st), ed(ed), x(x), l(nullptr), r(nullptr) {}
  };

  Node* root;

  void update(Node* u, int st, int ed) {
    if (u->x == u->ed - u->st + 1) return;

    if (st <= u->st && u->ed <= ed) {
      u->x = u->ed - u->st + 1;
      return;
    }

    int mid = u->st + u->ed >> 1;
    if (!u->l) u->l = new Node(u->st, mid, 0);
    if (!u->r) u->r = new Node(mid + 1, u->ed, 0);
    if (st <= mid) update(u->l, st, ed);
    if (ed > mid) update(u->r, st, ed);
    u->x = u->l->x + u->r->x;
    if (u->x == u->ed - u->st + 1 && (u->l || u->r)) u->l = u->r = nullptr;
  }

  CountIntervals() { root = new Node(1, 1e9, 0); }

  void add(int left, int right) { update(root, left, right); }

  int count() { return root->x; }
};
/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
// @lc code=ed
