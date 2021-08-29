#include <iostream>
using namespace std;

double a[12];
char op;

int main() {
    cin >> op;
    double sum = 0.0;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++) {
            cin >> a[j];
            if (j < 11 - i) sum += a[j];
        }

    if (op == 'S') printf("%.1lf\n", sum);
    else printf("%.1lf\n", sum / (12 * 12 - 12) * 2);

    return 0;
}