#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

using PII = pair<int, int>;

int c, l;
vector<PII> v;
map<int, int> mp;

int main() {
  scanf("%d%d", &c, &l);
  while (c--) {
    int l, r;
    scanf("%d%d", &l, &r);
    v.push_back({l, r});
  }
  while (l--) {
    int a, b;
    scanf("%d%d", &a, &b);
    mp[a] += b;
  }

  sort(v.begin(), v.end(),
       [&](auto &p1, auto &p2) { return p1.second < p2.second; });
  int res = 0;
  for (auto &p : v) {
    int l = p.first, r = p.second;
    if (auto it = mp.lower_bound(l); it != mp.end() && it->first <= r) {
      if (!--it->second)
        mp.erase(it);
      res++;
    }
  }

  printf("%d\n", res);
}
