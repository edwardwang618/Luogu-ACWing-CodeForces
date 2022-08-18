#include <iostream>
using namespace std;

int main() {
    double a;
    cin >> a;
    if (a < 0 || a > 100) puts("Fora de intervalo");
    else if (0 <= a && a <= 25) puts("Intervalo [0,25]");
    else if (25 < a && a <= 50) puts("Intervalo (25,50]");
    else if (50 < a && a <= 75) puts("Intervalo (50,75]");
    else if (75 < a && a <= 100) puts("Intervalo (75,100]");
    return 0;
}