/*
 * @lc app=leetcode id=1157 lang=cpp
 *
 * [1157] Online Majority Element In Subarray
 */

// @lc code=start
#if 0
class MajorityChecker {
public:
  unordered_map<int, vector<int>> mp;
  struct Node {
    int l, r;
    int maj;
  };
  vector<Node> tr;

  int cnt(int x, int l, int r) {
    if (auto it = mp.find(x); it != mp.end()) {
      auto &pos = it->second;
      return upper_bound(pos.begin(), pos.end(), r) -
             lower_bound(pos.begin(), pos.end(), l);
    }
    return 0;
  }

  void pushup(int u) {
    int l = tr[u].l, r = tr[u].r, half_len = r - l + 1 >> 1;
    int l_maj = tr[u << 1].maj, r_maj = tr[u << 1 | 1].maj;
    int &maj = tr[u].maj;
    if (cnt(l_maj, l, r) > half_len) {
      maj = l_maj;
      return;
    }
    if (cnt(r_maj, l, r) > half_len) {
      maj = r_maj;
      return;
    }
    maj = -1;
  }

  int ask(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r)
      return tr[u].maj;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) {
      int lmaj = ask(u << 1, l, r);
      if (~lmaj && cnt(lmaj, l, r) > r - l + 1 >> 1)
        return lmaj;
    }
    if (r > mid) {
      int rmaj = ask(u << 1 | 1, l, r);
      if (~rmaj && cnt(rmaj, l, r) > r - l + 1 >> 1)
        return rmaj;
    }
    return -1;
  }

  MajorityChecker(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
      mp[a[i]].push_back(i);
    tr.resize(n << 2);
    auto build = [&](this auto &&build, int u, int l, int r) -> void {
      tr[u] = {l, r, -1};
      if (l == r) {
        tr[u].maj = a[l];
        return;
      }
      int mid = l + r >> 1;
      build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
      pushup(u);
    };
    build(1, 0, n - 1);
  }

  int query(int l, int r, int threshold) {
    int maj = ask(1, l, r);
    if (cnt(maj, l, r) >= threshold)
      return maj;
    return -1;
  }
};
#endif

class MajorityChecker {
  unordered_map<int, vector<int>> mp;
  vector<int> &a;

public:
  MajorityChecker(vector<int> &a) : a(a) {
    for (int i = 0; i < a.size(); i++)
      mp[a[i]].push_back(i);
  }

  int cnt(int x, int l, int r) {
    auto it = mp.find(x);
    if (it == mp.end())
      return 0;
    auto &pos = it->second;
    return upper_bound(pos.begin(), pos.end(), r) -
           lower_bound(pos.begin(), pos.end(), l);
  }

  int query(int l, int r, int threshold) {
    for (int i = 0; i < 10; i++) {
      int idx = l + rand() % (r - l + 1);
      if (cnt(a[idx], l, r) >= threshold)
        return a[idx];
    }
    return -1;
  }
};
/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
// @lc code=end
