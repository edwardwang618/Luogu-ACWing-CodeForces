#include <iostream>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k % 3) n % 3 ? puts("Alice") : puts("Bob");
    else {
      n %= k + 1;
      n == k || n % 3 ? puts("Alice") : puts("Bob");
    }
  }
}