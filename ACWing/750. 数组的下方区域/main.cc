#include <iostream>
using namespace std;

int main() {
    double x, sum = 0.0;
    char ch;
    cin >> ch;
    for (int i = 0; i < 12; i++) 
        for (int j = 0; j < 12; j++) {
            cin >> x;
            if (i > j && j > 11 - i)
                sum += x;
        }

    if (ch == 'S') printf("%.1lf\n", sum);
    else printf("%.1lf\n", sum / ((10 + 2) * 5 / 2));

    return 0;
}