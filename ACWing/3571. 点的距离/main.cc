#include <iostream>
#include <cmath>
using namespace std;

struct CPoint {
  double x, y;
  double operator-(const CPoint& p) {
    double dx = x - p.x, dy = y - p.y;
    return sqrt(dx * dx + dy * dy);
  }
} p0, p1;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lf%lf%lf%lf", &p0.x, &p0.y, &p1.x, &p1.y);
    printf("%.2lf\n", p0 - p1);
  }
}