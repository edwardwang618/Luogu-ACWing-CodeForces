#include <iostream>
using namespace std;

double a[12];
char op;

int main() {
    double sum = 0.0;
    cin >> op;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++) {
            double x;
            cin >> x;
            if (i > j) sum += x;
        }
    
    printf("%.1lf\n", op == 'S' ? sum : sum / (12 * 12 - 12) * 2);
    return 0;
}