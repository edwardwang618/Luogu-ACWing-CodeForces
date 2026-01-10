/*
 * @lc app=leetcode id=3377 lang=cpp
 *
 * [3377] Digit Operations to Make Two Integers Equal
 */

// @lc code=start
class Solution {
public:
  int minOperations(int n, int m) {
    const int N = 10000;
    static vector<bool> is_prime;
    if (is_prime.empty()) {
      is_prime.assign(N, true);
      is_prime[0] = is_prime[1] = false;
      for (int i = 2; i < N; i++)
        if (is_prime[i]) {
          for (int j = 2 * i; j < N; j += i)
            is_prime[j] = false;
        }
    }

    if (is_prime[n] || is_prime[m]) return -1;

    vector<int> pw;
    for (int t = n, p = 1; t; t /= 10, p *= 10)
      pw.push_back(p);
    int len = pw.size();
    vector<int> dist(pw.back() * 10, INT_MAX);
    dist[n] = n;

    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.emplace(n, n);

    while (heap.size()) {
      auto [dis, x] = heap.top(); heap.pop();
      if (x == m) return dis;
      if (dis > dist[x]) continue;
      for (int i = 0; i < len; i++) {
        int d = (x / pw[i]) % 10;
        if (d != 9) {
          int nx = x + pw[i];
          if (!is_prime[nx] && dis + nx < dist[nx]) {
            dist[nx] = dis + nx;
            heap.emplace(dist[nx], nx);
          }
        }

        if (d && !(i == len - 1 && d == 1)) {
          int nx = x - pw[i];
          if (!is_prime[nx] && dis + nx < dist[nx]) {
            dist[nx] = dis + nx;
            heap.emplace(dist[nx], nx);
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
