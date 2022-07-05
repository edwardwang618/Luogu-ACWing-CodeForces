#include <iostream>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int res = 0;
    while (n--) {
      int x;
      scanf("%d", &x);
      res ^= x;
    }
    res ? puts("Yes") : puts("No");
  }
}