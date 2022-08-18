#include <iostream>
using namespace std;

int main() {
    char op;
    cin >> op;
    double x, s = 0.0;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (i + j > 11) s += x;
        }
    if (op == 'S') printf("%.1lf\n", s);
    else printf("%.1lf\n", s / (12 * 11 / 2));

    return 0;
}