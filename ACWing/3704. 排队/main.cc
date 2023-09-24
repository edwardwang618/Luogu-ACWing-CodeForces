#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 510, M = 5010;
int n, m;
int h[N], e[M], ne[M], idx;
int ind[N];
priority_queue<int, vector<int>, greater<>> heap;

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

void topo() {
  while (heap.size()) {
    auto u = heap.top(); heap.pop();
    printf("%d ", u);
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (!--ind[v]) heap.push(v);
    }
  }
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1, a, b; i <= m; i++)  
    scanf("%d%d", &a, &b), add(a, b), ind[b]++;

  for (int i = 1; i <= n; i++)
    if (!ind[i]) heap.push(i);

  topo();  
}