#include <iostream>
using namespace std;

int count1(int x) {
  x = (x & 0x55555555) + (x >> 1 & 0x55555555);
  x = (x & 0x33333333) + (x >> 2 & 0x33333333);
  x = (x & 0x0F0F0F0F) + (x >> 4 & 0x0F0F0F0F);
  x = (x & 0x00FF00FF) + (x >> 8 & 0x00FF00FF);
  x = (x & 0x0000FFFF) + (x >> 16 & 0x0000FFFF);
  return x;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    printf("%d ", count1(x));
  }
}