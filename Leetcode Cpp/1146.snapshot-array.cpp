/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
// class SnapshotArray {
//  public:
// #define x first
// #define y second
//   vector<vector<pair<int, int>>> vs;
//   int snap_id;

//   SnapshotArray(int length) {
//     snap_id = 0;
//     vs.resize(length, {{-1, 0}});
//   }

//   void set(int index, int val) {
//     auto &v = vs[index];
//     if (v.back().x == snap_id) v.back().y = val;
//     else v.push_back({snap_id, val});
//   }

//   int snap() {
//     return snap_id++;
//   }

//   int get(int index, int snap_id) {
//     auto &v = vs[index];
//     int l = 0, r = v.size() - 1;
//     while (l < r) {
//       int mid = l + (r - l + 1 >> 1);
//       if (v[mid].x <= snap_id) l = mid;
//       else r = mid - 1;
//     }

//     return v[l].y;
//   }
// };

class SnapshotArray {
 public:
  struct Node {
    Node* ne[10];
    int val;
    Node(int x) : val(x) { fill(ne, ne + 10, nullptr); }
    Node() : Node(0) {}
  };
  vector<Node*> v;
  SnapshotArray(int length) { v.push_back(new Node()); }

  void set(int index, int val) {
    string s = to_string(index);
    auto *p = v.back(), *q = p;
    for (char ch : s) {
      int idx = ch - '0';
      if (!p->ne[idx]) {
        p->ne[idx] = new Node();
        p = p->ne[idx];
      } else {
        q = p->ne[idx];
        p->ne[idx] = new Node(q->val);
        p = p->ne[idx];
        copy(q->ne, q->ne + 10, p->ne);
      }
    }

    p->val = val;
  }

  int snap() {
    auto *p = new Node(), *q = v.back();
    copy(q->ne, q->ne + 10, p->ne);
    v.push_back(p);
    return v.size() - 2;
  }

  int get(int index, int snap_id) {
    string s = to_string(index);
    auto* p = v[snap_id];
    for (char ch : s) {
      int idx = ch - '0';
      if (!p->ne[idx]) return 0;
      p = p->ne[idx];
    }

    return p->val;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end
