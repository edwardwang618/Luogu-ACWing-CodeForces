#include <iostream>
#include <vector>
using namespace std;

int main() {
  string a, b;
  auto add = [](auto& a, auto& b) {
    vector<int> res;
    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i++) {
      if (i < a.size()) t += a[i];
      if (i < b.size()) t += b[i];
      res.push_back(t % 10);
      t /= 10;
    }
    while (res.size() > 1 && !res.back()) res.pop_back();
    return res;
  };
  while (cin >> a >> b) {
    vector<int> x, y;
    for (int i = a.size() - 1; i >= 0; i--) x.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) y.push_back(b[i] - '0');
    auto res = add(x, y);
    for (int i = res.size() - 1; i >= 0; i--) printf("%d", res[i]);
    puts("");
  }
}