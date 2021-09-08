#include <iostream>
#include <cstring>
using namespace std;

bool used[10];

bool check(int x) {
    while (x) {
        if (used[x % 10] || x % 10 == 0) return false;
        used[x % 10] = true;
        x /= 10;
    }

    return true;
}

int main() {
    for (int i = 123; i < 333; i++) {
        int x1 = i, x2 = i * 2, x3 = i * 3;
        memset(used, 0, sizeof used);
        if (!check(x1) || !check(x2) || !check(x3)) continue;
        printf("%d %d %d\n", x1, x2, x3);
    }

    return 0;
}