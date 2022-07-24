#include <iostream>
using namespace std;

int n;

int main() {
  scanf("%d", &n);
  int res = 0;
  while (n--) {
    int x;
    scanf("%d", &x);
    res ^= x;
  }
  res ? puts("Yes") : puts("No");
}