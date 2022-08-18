#include <iostream>
using namespace std;

int main() {
    int a, n;
    cin >> a;
    while (cin >> n, n <= 0) cin >> n;

    int res = 0;
    for (int i = a; i < a + n; i++) res += i;
    printf("%d\n", res);

    return 0;
}