#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10, M = 5e4 * 2 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int stk[M], top;
int res[M], cnt;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void euler(int u) {
  stk[top++] = u;
  while (top) {
    u = stk[top - 1];
    if (~h[u]) {
        int v = e[h[u]];
        h[u] = ne[h[u]];
        stk[top++] = v;
    } else res[++cnt] = stk[--top];
  }
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }
  
  euler(1);
  for (int i = cnt; i; i--) printf("%d\n", res[i]);
}