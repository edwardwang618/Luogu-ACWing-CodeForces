#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
map<int, vector<int>> mp;

int main() {
  auto mult = [&](const vector<int> &a, int k) {
    vector<int> res;
    for (int i = 0, t = 0; i < a.size() || t; i++) {
      if (i == res.size()) res.push_back(0);
      res[i] = (i < a.size() ? a[i] * k : 0) + t;
      t = res[i] / 10000;
      res[i] %= 10000;
    }
    while (res.size() > 1 && !res.back()) res.pop_back();
    mp[k] = res;
    return res;
  };
  mp[1] = {1};
  auto calc = [&](int n) {
    if (mp.count(n)) return mp[n];
    int i = mp.rbegin()->first;
    auto a = mp.rbegin()->second;

    for (; i < n; i++) a = mult(a, i + 1);
    return a;
  };
  while (cin >> n) {
    vector<int> res = calc(n);
    for (int i = res.size() - 1; i >= 0; i--)
      if (i < res.size() - 1)
        printf("%04d", res[i]);
      else
        printf("%d", res[i]);
    puts("");
  }
}