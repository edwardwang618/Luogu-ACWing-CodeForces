#include <iostream>
using namespace std;

int a[110];

int main() {
    int x, idx = 0;
    while (cin >> x, x) a[idx++] = x;

    for (int i = idx - 1; i >= 0; i--) printf("%d ", a[i]);
    puts("");

    return 0;
}