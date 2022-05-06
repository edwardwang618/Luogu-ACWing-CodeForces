#include <iostream>
#include <algorithm>
using namespace std;

int a[4];

int main() {
  scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
  sort(a, a + 4);
  for (int i = 0; i < 3; i++) printf("%d ", a[3] - a[2 - i]);
}