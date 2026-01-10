/*
 * @lc app=leetcode id=2276 lang=cpp
 *
 * [2276] Count Integers in Intervals
 */

// @lc code=start
class CountIntervals {
public:
  using PII = pair<int, int>;
  set<PII> st;
  int covered = 0;
  static int len(int l, int r) { return r - l + 1; }

  CountIntervals() = default;

  void add(int l, int r) {
    auto it = st.lower_bound({l, 0});
    if (it != st.begin()) {
      auto pre = prev(it);
      if (pre->second >= l - 1)
        it = pre;
    }

    int L = l, R = r;
    while (it != st.end() && it->first <= r + 1) {
      L = min(L, it->first);
      R = max(R, it->second);
      covered -= len(it->first, it->second);
      it = st.erase(it);
    }

    st.emplace(L, R);
    covered += len(L, R);
  }

  int count() { return covered; }
};
/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
// @lc code=end
