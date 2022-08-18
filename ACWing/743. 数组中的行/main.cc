#include <iostream>
using namespace std;

double a[12];

int main() {
    int row;
    cin >> row;
    char ch;
    cin >> ch;

    double res = 0.0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++)
            scanf("%lf", &a[j]);
        if (i == row) {
            for (int j = 0; j < 12; j++) res += a[j];
            if (ch == 'S') printf("%.1lf\n", res);
            else printf("%.1lf\n", res / 12.0);
        }
    }

    return 0;
}