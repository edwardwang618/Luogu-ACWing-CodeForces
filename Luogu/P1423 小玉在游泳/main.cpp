#include <iostream>
using namespace std;

int main() {
    double x;
    cin >> x;
    int res = 0;
    for (double s = 0.0, t = 2.0; ; t *= 0.98) {
        if (s >= x) break;
        s += t;
        res++;
    }

    printf("%d\n", res);
    return 0;
}