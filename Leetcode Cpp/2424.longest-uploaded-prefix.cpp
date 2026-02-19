/*
 * @lc app=leetcode id=2424 lang=cpp
 *
 * [2424] Longest Uploaded Prefix
 */

// @lc code=start
class LUPrefix {
  vector<bool> a;
  int idx;

public:
  LUPrefix(int n) : a(n), idx(0) {}

  void upload(int video) {
    a[video - 1] = true;
    while (idx < a.size() && a[idx])
      idx++;
  }

  int longest() { return idx; }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
// @lc code=end
