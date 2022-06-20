#include <iostream>
using namespace std;

const int N = 110;
int n, m;
int p[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  scanf("%d%d", &n, &m);
  if (n != m) puts("NO");
  else {
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      p[find(a)] = find(b);
    }

    bool flag = true;
    for (int i = 2; i <= n; i++) 
      if (find(i) != find(i - 1)) {
        flag = false;
        puts("NO");
        break;
      }
    
    if (flag) puts("FHTAGN!");
  }
}