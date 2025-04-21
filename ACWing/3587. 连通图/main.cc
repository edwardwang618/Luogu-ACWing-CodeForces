#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
int p[N];

int find(int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      int px = find(x), py = find(y);
      p[px] = py;
    }

    int a = find(1);
    bool res = true;
    for (int i = 2; i <= n; i++) 
      if (find(i) != a) {
        res = false;
        break;
      }

    res ? puts("YES") : puts("NO");
  }
}