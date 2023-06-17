#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_set>
using namespace std;

const int N = 2e5 + 10, M = 2 * N;
int n;
int h[N], e[M], ne[M], idx;
bool vis[N];
queue<int> q, o;

#define add(a, b) e[idx] = b, ne[idx] = h[a], h[a] = idx++

bool bfs() {
  vis[1] = true;
  q.push(1);
  if (o.front() != 1) return false;
  o.pop();
  while (q.size()) {
    unordered_set<int> st;
    int t = q.front(); q.pop();
    for (int i = h[t]; ~i; i = ne[i]) {
      int v = e[i];
      if (vis[v]) continue;
      vis[t] = true;
      st.insert(v);
    }

    while (st.size()) {
      int t = o.front();
      if (!st.count(t)) return false;
      st.erase(t);
      q.push(t);
      o.pop();
    }
  }
  return true;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    o.push(x);
  }

  puts(bfs() ? "Yes" : "No");
}