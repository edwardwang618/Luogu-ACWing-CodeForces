#include <iostream>
using namespace std;

const int N = 61;
long a[N];

int main() {
    a[1] = 1;
    for (int i = 2; i <= 60; i++) a[i] = a[i - 1] + a[i - 2];
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        printf("Fib(%d) = %ld\n", k, a[k]);
    }

    return 0;
}