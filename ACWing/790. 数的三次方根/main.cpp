#include<iostream>
using namespace std;

const double eps = 1e-7;

int main() {
    double n;
    cin >> n;

    double l = -50, r = 50;
    while (l + eps < r) {
        double m = l + (r - l) / 2.0;
        if (m * m * m > n) r = m;
        else l = m;
    }

    printf("%.6lf", l);

    return 0;
}