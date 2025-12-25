/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
// class MyCalendarTwo {
// public:
//   struct Node {
//     int lc, rc;
//     int l, r;
//     int max, add;
//   };
//   vector<Node> tr;
//   int new_node(int l, int r) {
//     tr.emplace_back(0, 0, l, r, 0, 0);
//     return tr.size() - 1;
//   }
// #define lc(u) tr[u].lc
// #define rc(u) tr[u].rc

//   void pushdown(int u) {
//     int add = tr[u].add;
//     int mid = tr[u].l + tr[u].r >> 1;
//     if (!lc(u)) lc(u) = new_node(tr[u].l, mid);
//     auto &lc = tr[lc(u)];
//     lc.max += add, lc.add += add;
//     if (!rc(u)) rc(u) = new_node(mid + 1, tr[u].r);
//     auto &rc = tr[rc(u)];
//     rc.max += add, rc.add += add;
//     tr[u].add = 0;
//   }

//   void pushup(int u) {
//     tr[u].max = max(tr[lc(u)].max, tr[rc(u)].max);
//   }

//   void add(int u, int l, int r, int x) {
//     if (l <= tr[u].l && tr[u].r <= r) tr[u].max += x, tr[u].add += x;
//     else {
//       int mid = tr[u].l + tr[u].r >> 1;
//       pushdown(u);
//       if (l <= mid) add(lc(u), l, r, x);
//       if (r > mid) add(rc(u), l, r, x);
//       pushup(u);
//     }
//   }

//   int query(int u, int l, int r) {
//     if (l <= tr[u].l && tr[u].r <= r) return tr[u].max;
//     int mid = tr[u].l + tr[u].r >> 1;
//     int res = 0;
//     pushdown(u);
//     if (l <= mid) res = query(lc(u), l, r);
//     if (r > mid) res = max(res, query(rc(u), l, r));
//     return res;
//   }

//   MyCalendarTwo() { tr.emplace_back(0, 0, 0, 1e9, 0); }

//   bool book(int st, int ed) {
//     ed--;
//     if (query(0, st, ed) == 2) return false;
//     add(0, st, ed, 1);
//     return true;
//   }
// };

class MyCalendarTwo {
public:
  map<int, int> mp;
  bool book(int st, int ed) {
    ++mp[st];
    --mp[ed];
    int sum = 0;
    for (auto &[_, d] : mp) {
      sum += d;
      if (sum >= 3) {
        if (auto it = mp.find(st); it != mp.end()) {
          if (it->second == 1) mp.erase(it);
          else it->second--;
        }
        if (auto it = mp.find(ed); it != mp.end()) {
          if (it->second == -1) mp.erase(it);
          else it->second++;
        }
        return false;
      }
    }
    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end
