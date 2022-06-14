#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
char p[N], s[N];
int ne[N];

void build_ne() {
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j++;
    ne[i] = j;
  }
}

int main() {
  cin >> m >> p + 1 >> n >> s + 1;

  build_ne();

  for (int i = 1, j = 0; i <= n; i++) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == m) {
      printf("%d ", i - m);
      j = ne[j];
    }
  }
}