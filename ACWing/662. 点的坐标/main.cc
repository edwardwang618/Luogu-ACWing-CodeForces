#include <iostream>
using namespace std;

int main() {
    double x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) puts("Origem");
    else if (x == 0) puts("Eixo Y");
    else if (y == 0) puts("Eixo X");
    else if (x > 0) {
        if (y > 0) puts("Q1");
        else puts("Q4");
    } else if (x < 0) {
        if (y > 0) puts("Q2");
        else puts("Q3");
    }

    return 0;
}