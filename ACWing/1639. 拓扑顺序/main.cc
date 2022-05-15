#include <iostream>
using namespace std;

const int N = 1010, M = 10010;
int n, m, k;
struct Edge {
  int a, b;
} e[M];
int id[N];
int res[110], cnt;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &e[i].a, &e[i].b);
  
  scanf("%d", &k);
  for (int c = 0; c < k; c++) {
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      id[x] = i;
    }

    bool valid = true;
    for (int i = 1; i <= m; i++)
      if (id[e[i].a] > id[e[i].b]) {
        valid = false;
        break;
      }

    if (!valid) res[++cnt] = c;
  }

  for (int i = 1; i < cnt; i++) printf("%d ", res[i]);
  printf("%d", res[cnt]);
}