#include <iostream>
using namespace std;
using ull = unsigned long long;

const int N = 100010;
const ull P = 131;
int n, m;
char s[N];
ull h[N], p[N];

ull ha(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);

  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * P + s[i];
    p[i] = p[i - 1] * P;
  }

  while (m--) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    if (r1 - l1 != r2 - l2) puts("No");
    else ha(l1, r1) == ha(l2, r2) ? puts("Yes") : puts("No");
  }
}