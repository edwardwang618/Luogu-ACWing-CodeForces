#include <iostream>
using namespace std;

int main() {
    double s, in;
    int perc;
    scanf("%lf", &s);

    if (s <= 400) {
        in = s * 0.15; s += in; perc = 15;
    } else if (s <= 800) {
        in = s * 0.12; s += in; perc = 12;
    } else if (s <= 1200) {
        in = s * 0.1; s += in; perc = 10;
    } else if (s <= 2000) {
        in = s * 0.07; s += in; perc = 7;
    } else {
        in = s * 0.04; s += in; perc = 4;
    }

    printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %d %%", s, in, perc);

    return 0;
}