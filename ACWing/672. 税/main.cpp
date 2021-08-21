#include <iostream>
using namespace std;

int main() {
    double x;
    cin >> x;
    double res = 0;
    if (x <= 2000) puts("Isento");
    else if (x <= 3000) res = (x - 2000) * 0.08;
    else if (x <= 4500) res = 1000 * 0.08 + (x - 3000) * 0.18;
    else res = 1000 * 0.08 + 1500 * 0.18 + (x - 4500) * 0.28;

    if (res > 1e-9) printf("R$ %.2lf", res);

    return 0;
}