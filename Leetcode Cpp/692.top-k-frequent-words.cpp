/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
 public:
  using ull = unsigned long long;
  vector<string> topKFrequent(vector<string>& ws, int k) {
    const ull P = 131;
    unordered_map<ull, int> freq;
    unordered_map<ull, string> mp;
    for (auto& s : ws) {
      ull ha = 0;
      for (char ch : s) ha = ha * P + ch;
      freq[ha]++;
      mp[ha] = s;
    }

    auto cmp = [&](ull a, ull b) {
      int af = freq[a], bf = freq[b];
      if (af != bf) return af > bf;
      return mp[a] < mp[b];
    };
    priority_queue<ull, vector<ull>, decltype(cmp)> heap(cmp);
    for (auto& [ha, f] : freq) {
      if (heap.size() < k)
        heap.push(ha);
      else {
        int f1 = f, f2 = freq[heap.top()];
        if (f1 > f2 || (f1 == f2 && mp[ha] < mp[heap.top()])) {
          heap.pop();
          heap.push(ha);
        }
      }
    }

    vector<string> res;
    while (heap.size()) {
      res.push_back(mp[heap.top()]);
      heap.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
