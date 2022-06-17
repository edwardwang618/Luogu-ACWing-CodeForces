#include <iostream>
#include <cstring>
using namespace std;

const int N = 160, M = N * 70;
int n;
char s[1000010], ss[N][80];
int tr[M][26], ne[M], f[M], idx;
int id[N];
int q[M];

void insert(int k) {
  int p = 0;
  for (int i = 0; ss[k][i]; i++) {
    int c = ss[k][i] - 'a';
    if (!tr[p][c]) tr[p][c] = ++idx;
    p = tr[p][c];
  }
  id[k] = p;
}

void build() {
  int hh = 0, tt = 0;
  for (int i = 0; i < 26; i++)
    if (tr[0][i])
      q[tt++] = tr[0][i];

  while (hh < tt) {
    int t = q[hh++];
    for (int i = 0; i < 26; i++) {
      int &p = tr[t][i];
      if (p) ne[p] = tr[ne[t]][i], q[tt++] = p;
      else p = tr[ne[t]][i];
    }
  }
}

void query() {
  int p = 0;
  for (int i = 0; s[i]; i++) {
    p = tr[p][s[i] - 'a'];
    f[p]++;
  }
}

int main() {
  while (scanf("%d", &n), n) {
    idx = 0;
    memset(tr, 0, sizeof tr);
    memset(ne, 0, sizeof ne);
    memset(f, 0, sizeof f);
    memset(id, 0, sizeof id);
    for (int i = 1; i <= n; i++) {
      scanf("%s", ss[i]);
      insert(i);
    }
    build();
    scanf("%s", s);

    query();

    int max_cnt = 0;
    for (int i = idx - 1; i >= 0; i--) f[ne[q[i]]] += f[q[i]];
    for (int i = 1; i <= n; i++) max_cnt = max(max_cnt, f[id[i]]);
    printf("%d\n", max_cnt);
    for (int i = 1; i <= n; i++) if (f[id[i]] == max_cnt) printf("%s\n", ss[i]);
  }
}