#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, INF = 1e8;
int n, p;
int a[N];

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%d", &n, &p);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        int sum = 0;
        for (int i = 1; i < p; i++) sum += a[p] - a[i];
        int res = sum;
        for (int i = p + 1; i <= n; i++) {
            sum += (a[i] - a[i - 1]) * p - (a[i] - a[i - p]);
            res = min(res, sum);
        }

        printf("Case #%d: %d\n", T, res);
    }

    return 0;
}