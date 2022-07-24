#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 10010, M = N * 10;
int n, m;
int h[N], e[M], ne[M], idx;
int f[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int sg(int x) {
  if (~f[x]) return f[x];
  unordered_set<int> st;
  for (int i = h[x]; ~i; i = ne[i])
    st.insert(sg(e[i]));
  
  for (int i = 0;; i++)
    if (!st.count(i)) 
      return f[x] = i; 
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    while (m--) {
      int x;
      scanf("%d", &x);
      add(i, x);
    }
  }

  memset(f, -1, sizeof f);
  while (cin >> m, m) {
    int res = 0;
    while (m--) {
      int x;
      scanf("%d", &x);
      res ^= sg(x);
    }

    res ? puts("WIN") : puts("LOSE");
  }
}