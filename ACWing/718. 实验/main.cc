#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int c, r, f;
    c = r = f = 0;
    for (int i = 0; i < N; i++) {
        int x;
        char ch;
        cin >> x >> ch;
        if (ch == 'C') c += x;
        else if (ch == 'R') r += x;
        else f += x;
    }

    printf("Total: %d animals\n", c + r + f);
    printf("Total coneys: %d\n", c);
    printf("Total rats: %d\n", r);
    printf("Total frogs: %d\n", f);
    printf("Percentage of coneys: %.2lf %\n", (double) c / (c + r + f) * 100);
    printf("Percentage of rats: %.2lf %\n", (double) r / (c + r + f) * 100);
    printf("Percentage of frogs: %.2lf %\n", (double) f / (c + r + f) * 100);

    return 0;
}