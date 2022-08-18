#include <iostream>
using namespace std;

int a[110][110];

int main() {
    int n;
    while (cin >> n, n) {
        for (int i = 1; i <= (n - 1) / 2 + 1; i++)
            for (int j = i; j <= n - i + 1; j++)
                for (int k = i; k <= n - i + 1; k++)
                    a[j][k] = i;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                printf("%d ", a[i][j]);
            puts("");
        }
        puts("");
    }

    return 0;
}