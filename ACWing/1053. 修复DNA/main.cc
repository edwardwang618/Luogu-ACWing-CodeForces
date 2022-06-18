#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int n, m;
int tr[N][4], idx;
bool word[N];
int q[N], ne[N];
char s[N];
int mp['T' + 1];
int f[N][N];

void insert() {
  int p = 0;
  for (int i = 0; s[i]; i++) {
    int c = mp[s[i]];
    if (!tr[p][c]) tr[p][c] = ++idx;
    p = tr[p][c];
  }

  word[p] = true;
}

void build() {
  int hh = 0, tt = 0;
  for (int i = 0; i < 4; i++)
    if (tr[0][i]) q[tt++] = tr[0][i];
  
  while (hh < tt) {
    int t = q[hh++];
    for (int i = 0; i < 4; i++) {
      int p = tr[t][i];
      if (p) ne[p] = tr[ne[t]][i], q[tt++] = p, word[p] |= word[ne[p]];
      else tr[t][i] = tr[ne[t]][i];
    }
  }
}

int main() {
  mp['A'] = 0, mp['G'] = 1, mp['C'] = 2, mp['T'] = 3;
  int T = 1;
  while (scanf("%d", &n), n) {
    memset(tr, 0, sizeof tr);
    memset(word, 0, sizeof word);
    memset(ne, 0, sizeof ne);
    idx = 0;

    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      insert();
    }

    build();

    scanf("%s", s + 1);
    m = strlen(s + 1);

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j <= idx; j++) {
        if (word[j] || f[i][j] == 0x3f3f3f3f) continue;
        for (int k = 0; k < 4; k++) {
          int p = tr[j][k];
          if (word[p]) continue;
          f[i + 1][p] = min(f[i + 1][p], f[i][j] + (mp[s[i + 1]] != k));
        }
      }

    int res = 0x3f3f3f3f;
    for (int i = 0; i <= idx; i++) res = min(res, f[m][i]);

    if (res == 0x3f3f3f3f) res = -1;
    printf("Case %d: %d\n", T++, res);
  }
}