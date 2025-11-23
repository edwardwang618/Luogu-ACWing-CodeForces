/*
 * @lc app=leetcode id=2281 lang=cpp
 *
 * [2281] Sum of Total Strength of Wizards
 */

// @lc code=start
class Solution {
 public:
  int totalStrength(vector<int>& v) {
    const int MOD = 1e9 + 7;
    int n = v.size();
    long sum = 0, ss[n + 2];
    memset(ss, 0, sizeof ss);
    for (int i = 1; i <= n; i++) {
      sum += v[i - 1];
      ss[i + 1] = (ss[i] + sum) % MOD;
    }
    int l[n], r[n];
    fill(l, l + n, 0);
    fill(r, r + n, n);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      while (stk.size() && v[stk.top()] > v[i]) {
        r[stk.top()] = i;
        stk.pop();
      }

      l[i] = stk.size() ? stk.top() : -1;
      stk.push(i);
    }

    int res = 0;
    for (int k = 0; k < n; k++) {
      sum = ((k - l[k]) * (ss[r[k] + 1] - ss[k + 1]) % MOD -
             (r[k] - k) * (ss[k + 1] - ss[l[k] + 1]) % MOD) % MOD;
      sum = (sum + MOD) % MOD;
      res = (res + sum * v[k]) % MOD;
    }

    return res;
  }
};
// @lc code=end
