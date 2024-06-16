#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string a;
  vector<int> res;
  auto add = [](vector<int> &res, vector<int> &v) {
    for (int i = 0, t = 0; i < v.size() || i < res.size() || t; i++) {
      if (i < v.size()) t += v[i];
      if (i < res.size()) t += res[i];
      else res.push_back(0);
      res[i] = t % 10;
      t /= 10;
    }
    while (res.size() > 1 && !res.back()) res.pop_back();
  };
  while (cin >> a, a != "0") {
    vector<int> v;
    for (int i = a.size() - 1; i >= 0; i--) v.push_back(a[i] - '0');
    add(res, v);
  }

  for (int i = res.size() - 1; i >= 0; i--) printf("%d", res[i]);
}