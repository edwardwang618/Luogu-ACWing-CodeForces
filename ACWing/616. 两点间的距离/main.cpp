#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double dx = x1 - x2, dy = y1 - y2;
    printf("%.4lf\n", sqrt(dx * dx + dy * dy));
    return 0;
}