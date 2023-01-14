#include <iostream>
using namespace std;

const int V = 1010;
int f[V];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    int v, w;
    scanf("%d%d", &v, &w);
    for (int j = m; j >= v; j--) 
      f[j] = max(f[j], f[j - v] + w);
  }

  printf("%d\n", f[m]);
}