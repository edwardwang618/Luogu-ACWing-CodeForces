#include <iostream>
using namespace std;

const int N = 39 * 40 / 2 + 10;
int n, s;
int f[N];

int main() {
    scanf("%d", &n);
    s = n * (n + 1) / 2;
    if (s % 2 != 0) puts("0");
    else {
        f[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = s / 2; j >= i; j--)
                f[j] += f[j - i];

        printf("%d", f[s / 2] / 2);
    }

    return 0;
}