#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int deg[N][2];
vector<int> G[N];
int res[M], idx, del[N], cnt[3];

void dfs(int u) {
  for (int i = del[u]; i < G[u].size(); i = del[u]) {
    del[u]++;
    dfs(G[u][i]);
  }

  res[idx++] = u;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    deg[a][1]++, deg[b][0]++;
  }

  int S = 1;
  for (int i = 1; i <= n; i++) {
    if (deg[i][0] != deg[i][1]) cnt[0]++;
    if (deg[i][1] - deg[i][0] == 1) cnt[1]++, S = i;
    if (deg[i][0] - deg[i][1] == 1) cnt[2]++;
  }

  if (cnt[0] && (cnt[1] != 1 || cnt[2] != 1)) return !puts("No");

  for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
  dfs(S);
  for (int i = idx - 1; i >= 0; i--) printf("%d ", res[i]);
}