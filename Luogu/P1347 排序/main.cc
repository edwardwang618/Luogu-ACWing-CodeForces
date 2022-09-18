#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 30;
int n, m;
bool g[N][N];
int ind[N], ind1[N];
unordered_set<int> set;
int q[N];

int topsort() {
  memcpy(ind, ind1, sizeof ind);
  int hh = 0, tt = 0;
  for (int x : set)
    if (!ind[x]) q[tt++] = x;

  bool unique = true;
  while (hh < tt) {
    if (tt - hh > 1) unique = false;
    int u = q[hh++];
    for (int v = 1; v <= n; v++) {
      if (!g[u][v]) continue;
      ind[v]--;
      if (!ind[v]) q[tt++] = v;
    }
  }

  if (hh < set.size()) return 2;
  if (!unique || hh < n) return 0;
  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    string s;
    cin >> s;
    int x = s[0] - 'A' + 1, y = s[2] - 'A' + 1;
    if (!g[x][y]) {
      g[x][y] = true;
      ind1[y]++;
    }

    set.insert(x);
    set.insert(y);

    int res = topsort();
    if (!res) continue;
    if (res == 1) {
      printf("Sorted sequence determined after %d relations: ", i);
      for (int j = 0; j < n; j++) putchar(q[j] + 'A' - 1);
      puts(".");
    } else printf("Inconsistency found after %d relations.\n", i);

    exit(0);
  }

  puts("Sorted sequence cannot be determined.");
}