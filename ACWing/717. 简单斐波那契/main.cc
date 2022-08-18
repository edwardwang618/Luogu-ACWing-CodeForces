#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[2] = {0, 1};
    for (int i = 0; i < min(2, n); i++) printf("%d ", a[i]);
    for (int i = 2; i < n; i++) {
        a[i & 1] += a[i & 1 ^ 1];
        printf("%d ", a[i & 1]);
    }

    return 0;
}