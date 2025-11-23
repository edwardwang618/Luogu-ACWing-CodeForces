/*
 * @lc app=leetcode id=1825 lang=cpp
 *
 * [1825] Finding MK Average
 */

// @lc code=start
class MKAverage {
 public:
  queue<int> q;
  map<int, int> mp;
  int m, k;
  long sum;

  MKAverage(int m, int k) {
    this->m = m;
    this->k = k;
    sum = 0;
  }

  void addElement(int x) {
    q.push(x);
    mp[x]++;
    sum += x;

    if (q.size() > m) {
      if (!--mp[q.front()]) mp.erase(q.front());
      sum -= q.front();
      q.pop();
    }
  }

  int calculateMKAverage() {
    if (q.size() < m) return -1;
    int n = k, minv = 0, maxv = 0;
    auto it = mp.begin();
    while (n > 0) {
      minv += it->first * min(it->second, n);
      n -= min(it->second, n);
      if (n) it++;
    }

    auto itr = mp.rbegin();
    n = k;
    while (n > 0) {
      maxv += itr->first * min(itr->second, n);
      n -= min(itr->second, n);
      if (n) itr++;
    }

    return (sum - minv - maxv) / (m - 2 * k);
  }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(x);
 * int param_2 = obj->calculateMKAverage();
 */
// @lc code=end
