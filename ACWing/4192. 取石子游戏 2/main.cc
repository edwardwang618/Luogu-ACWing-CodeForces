#include <iostream>
using namespace std;

int n, res;

int main() {
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    res ^= x;
  }

  res ? puts("lose") : puts("yes");
}