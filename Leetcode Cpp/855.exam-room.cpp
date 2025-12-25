/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */

// @lc code=start
class ExamRoom {
  int N;
  using PII = pair<int, int>; // (l,r)
  struct Cmp {
    int N;
    int dist(const PII &in) const {
      auto [l, r] = in;
      if (l == -1) return r;
      if (r == N) return N - 1 - l;
      return (r - l) / 2;
    }
    int seatPos(const PII &in) const {
      auto [l, r] = in;
      if (l == -1) return 0;
      if (r == N) return N - 1;
      return l + r >> 1;
    }
    bool operator()(const PII &a, const PII &b) const {
      int da = dist(a), db = dist(b);
      if (da != db) return da > db;
      int sa = seatPos(a), sb = seatPos(b);
      return sa < sb;
    }
  };

  set<PII, Cmp> segs;
  set<int> occ;

  void addSeg(int l, int r) { segs.insert({l, r}); }
  void delSeg(int l, int r) { segs.erase({l, r}); }

public:
  ExamRoom(int n) : N(n), segs(Cmp{n}) { addSeg(-1, N); }

  int seat() {
    auto [l, r] = *segs.begin();
    int p = (l == -1 ? 0 : (r == N ? N - 1 : (l + r) / 2));
    delSeg(l, r);
    addSeg(l, p);
    addSeg(p, r);
    occ.insert(p);
    return p;
  }

  void leave(int p) {
    auto it = occ.find(p);
    int l = -1, r = N;
    if (it != occ.begin()) l = *prev(it);
    if (next(it) != occ.end()) r = *next(it);

    delSeg(l, p);
    delSeg(p, r);
    addSeg(l, r);

    occ.erase(it);
  }
};
/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end
