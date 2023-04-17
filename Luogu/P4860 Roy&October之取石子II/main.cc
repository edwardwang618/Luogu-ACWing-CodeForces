#include <iostream>
using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x;
    scanf("%d", &x);
    x % 4 ? puts("October wins!") : puts("Roy wins!");
  }
}