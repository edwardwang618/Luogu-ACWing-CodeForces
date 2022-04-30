#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int n;
int p[N], sz[N];

int find(int x) {
  if (x != p[x]) p[x] = find(p[x]);
  return p[x];
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      sz[i] = 1;
    }

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      int pi = find(i), px = find(x);
      if (pi != px) {
        p[pi] = px;
        sz[px] += sz[pi];
      }
    }
    
    for (int i = 1; i <= n; i++) printf("%d ", sz[find(i)]);
    puts("");
  }
}