#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int n, m;
int p[N];
struct Edge {
  int a, b, len;
} e[N * (N - 1) / 2];

int find(int x) {
  if (x != p[x]) p[x] = find(p[x]);
  return p[x];
}

int main() {
  while (cin >> n, n) {
    for (int i = 1; i <= n; i++) p[i] = i;
    m = n * (n - 1) / 2;
    for (int i = 0; i < m; i++)
      scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].len);
    
    sort(e, e + m, [](const Edge& e1, const Edge& e2) {
      return e1.len < e2.len;
    });

    int res = 0;
    for (int i = 0; i < m; i++) {
      int pa = find(e[i].a), pb = find(e[i].b);
      if (pa != pb) {
        p[pa] = pb;
        res += e[i].len;
      }
    }

    printf("%d\n", res);
  }
}