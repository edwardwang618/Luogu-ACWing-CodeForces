/*
 * @lc app=leetcode id=805 lang=cpp
 *
 * [805] Split Array With Same Average
 */

// @lc code=start
class Solution {
 public:
  bool splitArraySameAverage(vector<int> &A) {
    int sum = 0;
    for (int x : A) sum += x;
    int g = gcd(sum, A.size());
    int a = sum / g, b = A.size() / g;
    for (int &x : A) x = x * b - a;
    unordered_map<int, int> mp;
    return dfs1(0, 0, 0, A, mp) || dfs2(A.size() / 2, 0, 0, A, mp);
  }

  bool dfs2(int u, int cnt, int sum, vector<int> &A,
            unordered_map<int, int> &mp) {
    auto it = mp.find(-sum);
    if (it != mp.end() && it->second + cnt && it->second + cnt < A.size())
      return true;
    for (int i = u; i < A.size(); i++)
      if (dfs2(i + 1, cnt + 1, sum + A[i], A, mp)) return true;

    return false;
  }

  bool dfs1(int u, int cnt, int sum, vector<int> &A,
            unordered_map<int, int> &mp) {
    if (!sum && cnt && cnt < A.size()) return true;
    auto it = mp.find(sum);
    if (it == mp.end() || it->second > cnt) mp[sum] = cnt;
    for (int i = u; i < A.size() / 2; i++)
      if (dfs1(i + 1, cnt + 1, sum + A[i], A, mp)) return true;

    return false;
  }

  int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
};
// @lc code=end
