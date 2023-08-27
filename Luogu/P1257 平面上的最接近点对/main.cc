#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

const int N = 1e4 + 10;
int n;
struct Point {
  double x, y;
} p[N];
double res;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  res = numeric_limits<double>::max();
  auto f = [](Point& p1, Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
  };
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      res = min(res, f(p[i], p[j]));
  
  printf("%.4lf\n", sqrt(res));
}