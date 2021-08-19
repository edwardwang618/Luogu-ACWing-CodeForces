#include <iostream>
using namespace std;

int main() {
    int x;
    double res = 0;
    cin >> x;

    int a = 0, b = 0, c = 0;
    if (x <= 150) a = x;
    else a = 150;

    if (150 < x && x <= 400) b = x - 150;
    else if (x > 400) b = 400 - 150;

    if (x > 400) c = x - 400;

    printf("%.1lf\n", a * 0.4463 + b * 0.4663 + c * 0.5663);
    return 0;
}