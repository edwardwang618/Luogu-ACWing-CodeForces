#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 5e3 + 10, M = N << 1;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool vis[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
  stack<int> stk;
  for (int i = 1; i <= n; i++) {
    stk.push(i);
    vis[i] = true;
  }

  while (stk.size()) {
    int t = stk.top(); stk.pop();
    vis[t] = false;
    for (int i = h[t]; ~i; i = ne[i]) {
      int v = e[i];
      if (dist[v] > dist[t] + w[i]) {
        dist[v] = dist[t] + w[i];
        cnt[v] = cnt[t] + 1;
        if (cnt[v] > n - 1) return false;
        if (!vis[v]) {
          stk.push(v);
          vis[v] = true;
        }
      }
    }
  }

  return true;
}

int main() {
  memset(h, -1, sizeof h);

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int type, a, b, c;
    scanf("%d", &type);
    if (type == 3) {
      scanf("%d%d", &a, &b);
      add(a, b, 0), add(b, a, 0);
    } else {
      scanf("%d%d%d", &a, &b, &c);
      if (type == 1) add(a, b, -c);
      else add(b, a, c);
    }
  }

  if (spfa()) puts("Yes");
  else puts("No");
}