#include <iostream>
#include <climits>
using namespace std;

const int N = 1e5 + 10;
int n;
long a[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%ld", &a[i]);
    int res = 0;
    long sum = 0, maxs = LONG_MIN;
    for (int k = 1; k <= n; k++) {
        sum = 0;
        int i = 1;
        for (i = 1 << k - 1; i < min((long) n + 1, 1L << k); i++)
            sum += a[i];
    
        if (sum > maxs) {
            res = k;
            maxs = sum;
        }

        if (i == n + 1) break;
    }

    printf("%ld\n", res);

    return 0;
}