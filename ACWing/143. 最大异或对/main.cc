#include <iostream>
using namespace std;

const int N = 100010, M = 31 * N;
int a[N], son[M][2], idx;

void insert(int x) {
  int p = 0;
  for (int i = 30; i >= 0; i--) {
    int u = x >> i & 1;
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
  }
}

int query(int x) {
  int res = 0;
  int p = 0;
  for (int i = 30; i >= 0; i--) {
    int u = x >> i & 1;
    if (son[p][!u]) {
      p = son[p][!u];
      res |= (!u) << i;
    } else {
      p = son[p][u];
      res |= u << i;
    }
  }

  return res;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  int res = 0;
  for (int i = 0; i < n; i++) {
    insert(a[i]);
    res = max(res, query(a[i]) ^ a[i]);
  }

  cout << res << endl;
}