#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int p[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) p[i] = i;

  while (m--) {
    char op;
    int a, b;
    cin >> op;
    cin >> a >> b;
    int pa = find(a), pb = find(b);
    if (op == 'M') p[pa] = pb;
    else if (op == 'Q') pa == pb ? puts("Yes") : puts("No");
  }
}