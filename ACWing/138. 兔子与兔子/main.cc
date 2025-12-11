#include <iostream>
#include <cstring>
using namespace std;
using ull = unsigned long long;

const int N = 1e6 + 10, P = 131;
int n, m;
char s[N];
ull ha[N], po[N];

ull get_hash(int l, int r) { return ha[r] - ha[l - 1] * po[r - l + 1]; }

int main() {
  scanf("%s", s + 1);
  scanf("%d", &m);

  n = strlen(s + 1);
  po[0] = 1;
  for (int i = 1; i <= n; i++) {
    ha[i] = ha[i - 1] * P + s[i];
    po[i] = po[i - 1] * P;
  }

  while (m--) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    puts(get_hash(l1, r1) == get_hash(l2, r2) ? "Yes" : "No");
  }
}