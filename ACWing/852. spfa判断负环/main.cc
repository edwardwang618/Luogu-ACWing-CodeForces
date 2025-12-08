#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 2010, M = 10010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
bool vis[N];
int dist[N], cnt[N];

#define add(a, b, c) \
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++

bool spfa() {
  stack<int> stk;
  for (int i = 1; i <= n; i++) {
    stk.push(i);
    vis[i] = true;
  }

  while (stk.size()) {
    int u = stk.top(); stk.pop();
    vis[u] = false;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i], c = w[i];
      if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        cnt[v] = cnt[u] + 1;
        if (cnt[v] >= n) return true;

        if (!vis[v]) {
          stk.push(v);
          vis[v] = true;
        }
      }
    }
  }

  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c);
  }

  puts(spfa() ? "Yes" : "No");
}