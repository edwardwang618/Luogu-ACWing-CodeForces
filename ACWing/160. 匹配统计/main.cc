#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int n, m, q;
char a[N], b[N];
int ne[N], cnt[N];

void build_ne() {
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && b[i] != b[j + 1]) j = ne[j];
    if (b[i] == b[j + 1]) j++;
    ne[i] = j; 
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  scanf("%s%s", a + 1, b + 1);
  build_ne();

  for (int i = 1, j = 0; i <= n; i++) {
    while (j && a[i] != b[j + 1]) j = ne[j];
    if (a[i] == b[j + 1]) j++;
    cnt[j]++;
  }

  for (int i = m; i; i--) cnt[ne[i]] += cnt[i];
  while (q--) {
    int l;
    scanf("%d", &l);
    printf("%d\n", cnt[l] - cnt[l + 1]);
  }
}