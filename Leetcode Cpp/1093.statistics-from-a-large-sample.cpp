/*
 * @lc app=leetcode id=1093 lang=cpp
 *
 * [1093] Statistics from a Large Sample
 */

// @lc code=start
class Solution {
 public:
  vector<double> sampleStats(vector<int>& cnt) {
    int m = INT_MAX, M = INT_MIN, mode = 0, amount = 0, max_cnt = 0;
    double sum = 0.0;
    for (int i = 0; i < cnt.size(); i++) {
      if (cnt[i]) {
        m = min(m, i), M = max(M, i);
        sum += (double)i * cnt[i];
        amount += cnt[i];
        if (cnt[i] > max_cnt) {
          max_cnt = cnt[i];
          mode = i;
        }
      }
    }

    double ave = sum / amount;
    auto f = [&](int k) {
      int amount = 0;
      for (int i = m; i <= M; i++) {
        amount += cnt[i];
        if (amount >= k) return i;
      }

      return -1;
    };

    double mean = 0.0;
    if (amount % 2) mean = f(amount / 2 + 1);
    else mean = (f(amount / 2) + f(amount / 2 + 1)) / 2.0;

    return {(double)m, (double)M, ave, mean, (double)mode};
  }
};
// @lc code=end
