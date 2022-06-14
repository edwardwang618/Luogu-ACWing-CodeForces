#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10, S = 55, M = 1e6 + 10;
int n;
int tr[N * S][26], cnt[N * S], idx;
char s[M];
int q[N * S], ne[N * S];

void insert() {
  int p = 0;
  for (int i = 0; s[i]; i++) {
    int t = s[i] - 'a';
    if (!tr[p][t]) tr[p][t] = ++idx;
    p = tr[p][t];
  }
  cnt[p]++;
}

void build() {
  int hh = 0, tt = 0;
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q[tt++] = tr[0][i];
  
  while (hh < tt) {
    int t = q[hh++];
    for (int i = 0; i < 26; i++) {
      int c = tr[t][i];
      if (!c) continue;
      int j = ne[t];
      while (j && !tr[j][i]) j = ne[j];
      if (tr[j][i]) j = tr[j][i];
      ne[c] = j;
      q[tt++] = c;
    }
  }
}

int query() {
  int res = 0;
  for (int i = 0, j = 0; s[i]; i++) {
    int t = s[i] - 'a';
    while (j && !tr[j][t]) j = ne[j];
    if (tr[j][t]) j = tr[j][t];

    int p = j;
    while (p) {
      res += cnt[p];
      cnt[p] = 0;
      p = ne[p];
    }
  }

  return res;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(tr, 0, sizeof tr);
    memset(cnt, 0, sizeof cnt);
    memset(ne, 0, sizeof ne);
    idx = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      insert();
    }

    build();
    scanf("%s", s);
    printf("%d\n", query());
  }
}