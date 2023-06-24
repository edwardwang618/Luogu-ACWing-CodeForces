#include <cstring>
#include <iostream>
using namespace std;

const int N = 210, INF = 0x3f3f3f3f;
int n, m;
int tm[N];
int g[N][N];

void update(int cur_city) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      g[i][j] = min(g[i][j], g[i][cur_city] + g[cur_city][j]);
}

int main() {
  memset(g, 0x3f, sizeof g);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &tm[i]);
    g[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    g[a][b] = g[b][a] = min(g[a][b], w);
  }

  int Q;
  scanf("%d", &Q);
  int cur_city = 0;
  while (Q--) {
    int a, b, t;
    scanf("%d%d%d", &a, &b, &t);
    while (tm[cur_city] <= t && cur_city < n) update(cur_city++);

    printf("%d\n",
           a < cur_city && b < cur_city && g[a][b] < INF ? g[a][b] : -1);
  }
}