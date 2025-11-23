/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
 public:
  string getPermutation(int n, int k) {
    // 缓存一下0到9的每个数的阶乘
    static constexpr array<int, 10> fact = []() {
      array<int, 10> f = {1};
      for (int i = 1; i < 10; ++i) {
        f[i] = f[i - 1] * i;
      }
      return f;
    }();
    string res;
    // 康托展开中的字典序排名是从0开始计数的所以要将k减去1
    k -= 1;

    // 将1到n这n个数正序存进一个列表
    vector<int> a;
    for (int i = 1; i <= n; ++i) a.push_back(i);

    // 开始从左向右求康托展开的系数
    for (int i = n - 1; i >= 0; i--) {
      // a就是当前项的系数，而nums[a]恰好就是nums里的第a + 1小的数，满足条件
      int x = k / fact[i];
      res += to_string(a[x]);
      // 将第a + 1小的数删去，这里的remove的参数是index
      a.erase(a.begin() + x);

      // 算一下余数，继续循环
      k %= fact[i];
    }

    return res;
  }
};
// @lc code=end
