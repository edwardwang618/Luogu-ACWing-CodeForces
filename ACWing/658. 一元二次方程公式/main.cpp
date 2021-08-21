#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    if (!a || delta < 0) puts("Impossivel calcular");
    else {
        double x1 = (-b + sqrt(delta)) / 2 / a;
        double x2 = (-b - sqrt(delta)) / 2 / a;
        printf("R1 = %.5lf\nR2 = %.5lf\n", x1, x2);
    }

    return 0;
}