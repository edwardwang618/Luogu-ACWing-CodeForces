#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x == 1) printf("Total: R$ %.2lf\n", y * 4.0);
    if (x == 2) printf("Total: R$ %.2lf\n", y * 4.5);
    if (x == 3) printf("Total: R$ %.2lf\n", y * 5.0);
    if (x == 4) printf("Total: R$ %.2lf\n", y * 2.0);
    if (x == 5) printf("Total: R$ %.2lf\n", y * 1.5);

    return 0;
}