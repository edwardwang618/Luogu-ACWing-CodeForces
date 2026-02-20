/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
class SummaryRanges {
  static constexpr int INF = 2e9;
  set<pair<int, int>> st;

public:
  SummaryRanges() {
    st.emplace(-INF, -INF);
    st.emplace(INF, INF);
  }

  void addNum(int x) {
    auto p = make_pair(x, x);
    auto it = st.lower_bound(p);
    if (x == it->first)
      return;
    auto it_left = prev(it);
    if (x <= it_left->second)
      return;
    auto it_right = st.upper_bound(p);
    if (it_left->second == x - 1) {
      p.first = it_left->first;
      st.erase(it_left);
    }
    if (it_right->first == x + 1) {
      p.second = it_right->second;
      st.erase(it_right);
    }
    st.insert(p);
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> res;
    res.reserve(st.size());
    for (auto &[l, r] : st)
      if (l != -INF && l != INF)
        res.push_back({l, r});
    return res;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end
