#include <iostream>
using namespace std;

int main() {
    int a[] = {100, 50, 20, 10, 5, 2};
    double b[] = {1, 0.5, 0.25, 0.1, 0.05, 0.01};

    puts("NOTAS:");
    double m; 
    cin >> m;
    int n = 100 * m;
    for (int i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %.2lf\n", n / (a[i] * 100), (double) a[i]);
        n %= (int) (a[i] * 100);
    }

    puts("MOEDAS:");
    for (int i = 0; i < 6; i++) {
        printf("%d moeda(s) de R$ %.2lf\n", n / (int) (b[i] * 100), b[i]);
        n %= (int) (b[i] * 100);
    }

    return 0;
}