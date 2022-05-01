#include <iostream>
using namespace std;

int n, t;
double res;

int main() {
  scanf("%d%d", &n, &t);
  double a = 1.00011;
  res = n;
  while (t) {
    if (t & 1) res *= a;
    a *= a;
    t >>= 1;
  }
  
  printf("%.6lf\n", res);
}
