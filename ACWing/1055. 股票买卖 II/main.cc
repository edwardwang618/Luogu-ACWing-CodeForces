#include <iostream>
using namespace std;

int n, pre = 1e9;

int main() {
  scanf("%d", &n);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    res += max(0, x - pre);
    pre = x;
  }
  printf("%d\n", res);
}