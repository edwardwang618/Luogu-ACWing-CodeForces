#include <iostream>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    int res = 0;
    for (int d = x; d < x + n; d++) {
        int c = (d - 1) % 7 + 1;
        if (c >= 6) continue;
        res += 250;
    }

    printf("%d\n", res);
    return 0;
}