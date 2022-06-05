#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using UL = unsigned long;

const int N = 3e5 + 10, P = 131, INF = 1e9;
int n;
char s[N];
int sa[N];
UL h[N], p[N];

void init() {
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * P + s[i];
    p[i] = p[i - 1] * P;
    sa[i] = i;
  }
}

UL ha(int l, int r) {
  return h[r] - h[l - 1] * p[r - l + 1];
}

int lcp(int i, int j) {
  int l = 0, r = n - max(i, j) + 1;
  while (l < r) {
    int mid = l + (r - l + 1 >> 1);
    if (ha(i, i + mid - 1) == ha(j, j + mid - 1)) l = mid;
    else r = mid - 1;
  }

  return l;
}

bool cmp(int i, int j) {
  int len = lcp(i, j);
  int a = i + len > n ? -INF : s[i + len];
  int b = j + len > n ? -INF : s[j + len];
  return a <= b;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);

  init();
  sort(sa + 1, sa + 1 + n, cmp);
  for (int i = 1; i <= n; i++) printf("%d ", sa[i] - 1);
  puts("");
  for (int i = 1; i <= n; i++) printf("%d ", lcp(sa[i - 1], sa[i]));
}