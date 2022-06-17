#include <iostream>
using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10;
int n;
char s[M];
int tr[N][26], ne[N], f[N], idx;
int id[N];
int q[N];

void insert(int k) {
  int p = 0;
  for (int i = 0; s[i]; i++) {
    int c = s[i] - 'a';
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
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    insert(i);
  }
  build();
  scanf("%s", s);

  query();

  for (int i = idx - 1; i >= 0; i--) f[ne[q[i]]] += f[q[i]];
  for (int i = 1; i <= n; i++) printf("%d\n", f[id[i]]);
}