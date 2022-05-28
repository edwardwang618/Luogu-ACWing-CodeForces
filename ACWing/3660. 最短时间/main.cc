#include <iostream>
using namespace std;

int n, m, r, c;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &n, &m, &r, &c);    
    int dx = max(r - 1, n - r), dy = max(c - 1, m - c);
    printf("%d\n", dx + dy);
  }
}