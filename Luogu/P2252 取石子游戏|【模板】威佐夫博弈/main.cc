#include <iostream>
#include <cmath>
using namespace std;

int n, m;
const double phi = (sqrt(5.0) + 1.0) / 2.0;

int main() {
  scanf("%d%d", &n, &m);
  if (n > m) swap(n, m);
  printf("%d\n", n == int(phi * (double)(m - n)) ? 0 : 1);
}