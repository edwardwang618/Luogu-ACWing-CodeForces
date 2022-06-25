#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e6 + 10, P = 131;
char s[N], t[N];
int n, h[N], rh[N], pow[N];

void init() {
  pow[0] = 1;
  h[0] = 0, rh[n + 1] = 0;
  for (int i = 1; i <= n; i++) h[i] = h[i - 1] * P + s[i], pow[i] = pow[i - 1] * P;
  for (int i = n; i; i--) rh[i] = rh[i + 1] * P + s[i];
}

int get_h(int l, int r) {
  return h[r] - h[l - 1] * pow[r - l + 1];
}

int get_rh(int l, int r) {
  return rh[l] - rh[r + 1] * pow[r - l + 1];
}

bool check(int len) {
  len = len / 2 + 1;
  for (int i = len; i + len - 1 <= n; i++)
    if (get_h(i - len + 1, i) == get_rh(i, i + len - 1)) return true;
  return false;
}

int main() {
  int T = 0;
  while (++T) {
    n = 0;
    scanf("%s", t + 1);
    if (!strcmp(t + 1, "END")) break;
    s[++n] = '$';
    for (int i = 1; t[i]; i++) s[++n] = t[i], s[++n] = '$';
    init();
    int l = 1, r = n;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (check(mid)) l = mid;
      else r = mid - 1;
    }

    printf("Case %d: %d\n", T, l / 2);
  }
}