/*
 * @lc app=leetcode id=1505 lang=cpp
 *
 * [1505] Minimum Possible Integer After at Most K Adjacent Swaps On Digits
 */

// @lc code=start
class Solution {
public:
  string minInteger(string &s, int k) {
    int n = s.size();
    s = " " + s;
    queue<int> pos[10];
    for (int i = 1; i <= n; i++)
      pos[s[i] - '0'].push(i);

    vector<int> tr(n + 1);
    auto lowbit = [](int x) { return x & -x; };
    auto add = [&](int i, int x) {
      for (; i <= n; i += lowbit(i)) tr[i] += x;
    };
    auto sum = [&](int i) {
      int s = 0;
      for (; i; i -= lowbit(i)) s += tr[i];
      return s;
    };

    string res;
    for (int i = 1; i <= n; i++)
      for (int d = 0; d <= 9; d++) {
        if (pos[d].empty()) continue;
        // move j to i
        int j = pos[d].front();
        int cost = j - 1 - sum(j - 1);
        if (cost <= k) {
          k -= cost;
          res += '0' + d;
          pos[d].pop();
          add(j, 1);
          break;
        }
        // int real_pos = j + sum(j);
        // if (real_pos - i <= k) {
        //   k -= real_pos - i;
        //   res += '0' + d;
        //   pos[d].pop();
        //   add(1, 1);
        //   add(j, -1);
        //   break;
        // }
      }
    return res;
  }
};
// @lc code=end
