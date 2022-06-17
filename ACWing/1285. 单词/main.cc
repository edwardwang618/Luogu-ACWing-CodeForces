#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int tr[N][26], f[N], idx;
int q[N], ne[N];
char s[N];
int id[210];

void insert(int k) {
  int p = 0;
  for (int i = 0; s[i]; i++) {
    int j = s[i] - 'a';
    if (!tr[p][j]) tr[p][j] = ++idx;
    p = tr[p][j];
    f[p]++;
  }
  id[k] = p;
}

void build() {
  int hh = 0, tt = 0;
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) q[tt++] = tr[0][i];

  while (hh < tt) {
    int t = q[hh++];
    for (int i = 0; i < 26; i++) {
      int &p = tr[t][i];
      if (p) ne[p] = tr[ne[t]][i], q[tt++] = p;
      else p = tr[ne[t]][i];
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    insert(i);
  }
  build();
  for (int i = idx - 1; i >= 0; i--) f[ne[q[i]]] += f[q[i]];
  for (int i = 0; i < n; i++) printf("%d\n", f[id[i]]);
}