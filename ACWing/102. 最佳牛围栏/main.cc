#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, f;
int a[N], s[N];

bool check(double x) {
  double min_s = 0;
  for (int i = f; i <= n; i++) {
    double cur = s[i] - i * x;
    min_s = min(min_s, s[i - f] - (i - f) * x);
    if (cur >= min_s) return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &f);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] + a[i];
  }

  double l = 0, r = 2000;
  while (r - l > 1e-9) {
    double mid = (l + r) / 2.0;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", (int)(r * 1000));
}