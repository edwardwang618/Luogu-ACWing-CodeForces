#include <iostream>
using namespace std;

double s[12];

int main() {
    int c; 
    cin >> c;
    char op;
    cin >> op;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++) {
            double x;
            cin >> x;
            s[j] += x;
        }

    if (op == 'S') printf("%.1lf\n", s[c]);
    else printf("%.1lf\n", s[c] / 12);

    return 0;
}