#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010, M = 5e5 + 10;
int n;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
pair<int, int> ed[M >> 1];
int cnt;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
  dfn[u] = low[u] = ++timestamp;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfn[u]) {
        int a = u, b = v;
        if (a > b) swap(a, b);
        ed[cnt++] = {a, b};
      }
    } else if (v != from) low[u] = min(low[u], low[v]);
  }
}

int main() {
  while (cin >> n) {
    memset(h, -1, sizeof h);
    idx = 0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    timestamp = cnt = 0;

    for (int i = 0; i < n; i++) {
      int u, k;
      scanf("%d (%d)", &u, &k);
      while (k--) {
        int v;
        scanf("%d", &v);
        add(u, v), add(v, u);
      }
    }

    for (int i = 0; i < n; i++)
      if (!dfn[i])
        tarjan(i, -1);
    
    sort(ed, ed + cnt);
    printf("%d critical links\n", cnt);
    for (int i = 0; i < cnt; i++)
      printf("%d - %d\n", ed[i].first, ed[i].second);

    puts("");
  }
}