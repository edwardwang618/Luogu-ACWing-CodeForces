#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
int n;
vector<int> g[N];
int p[N], sz[N];

int find(int x) {
  return x == p[x] ? x : p[x] = find(p[x]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int m;
    scanf("%d", &m);
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      g[i].push_back(x);
    }
  }
  
  auto f = [&](int k) {
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      sz[i] = 1;
    }
    for (int u = k + 1; u <= n; u++)
      for (int v : g[u]) {
        if (v <= k) continue;
        int pu = find(u), pv = find(v);
        if (pu != pv) {
          p[pu] = pv;
          sz[pv] += sz[pu];
        }
      }
    for (int i = 1; i <= n; i++) if (sz[find(i)] > n / 2) return false;
    return true;
  };
  
  int l = 1, r = n;
  while (l < r) {
    int mid = l + (r - l >> 1);
    if (f(mid)) r = mid;
    else l = mid + 1;
  }

  printf("%d\n", l);
}