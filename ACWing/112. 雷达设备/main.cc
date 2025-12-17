#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using PDD = pair<double, double>;

vector<PDD> v;
int n, d;

int main() {
  scanf("%d%d", &n, &d);
  v.reserve(n);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    if (d < y) {
      res = -1;
      break;
    }
    double r = sqrt(d * d - y * y);
    v.emplace_back(x - r, x + r);
  }
  if (~res) {
    sort(v.begin(), v.end(),
         [&](auto &a, auto &b) { return a.second < b.second; });

    double cur_x = -2e9;
    for (auto &[l, r] : v)
      if (cur_x < l) {
        cur_x = r;
        res++;
      }
  }
  printf("%d\n", res);
}