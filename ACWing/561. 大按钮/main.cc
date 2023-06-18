#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;

const int N = 6010;
int n, m;
int son[N][2], idx;
bool is_word[N];
char s[110];

void add() {
  int p = 0;
  for (int i = 1; s[i]; i++) {
    int u = s[i] == 'B' ? 0 : 1;
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }
  is_word[p] = true;
}

ll dfs(int u, int dep) {
  if (is_word[u]) return 1ll << n - dep;
  ll res = 0;
  if (son[u][0]) res += dfs(son[u][0], dep + 1);
  if (son[u][1]) res += dfs(son[u][1], dep + 1);
  return res;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    idx = 0;
    memset(son, 0, sizeof son);
    memset(is_word, 0, sizeof is_word);
    scanf("%d%d", &n, &m);
    while (m--) {
      scanf("%s", s + 1);
      add();
    }

    printf("Case #%d: %lld\n", i, (1ll << n) - dfs(0, 0));
  }
}