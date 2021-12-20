#include <iostream>
#include <cmath>

using namespace std;

int a, b;

bool check(int x) {
    int a = x, b = 0, cnt = 0;
    while (x) {
        b = b * 10 + x % 10;
        x /= 10;
        cnt++;
    }

    return a == b && (cnt % 2 || a == 11);
}

bool is_prime(int x) {
    int j = sqrt(x);
    for (int i = 2; i <= j; i++)
        if (x % i == 0) return false;

    return true;
}

int main() {
    scanf("%d%d", &a, &b);
    if (a % 2 == 0) a++;

    for (int i = a; i <= b; i += 2) {
        if (i == 1001 || i == 100001 || i == 10000001) {
            i = (i - 1) * 10 + 1;
            continue;
        }

        if (!check(i)) continue;
        if (is_prime(i)) printf("%d\n", i);
    }

    return 0;
}