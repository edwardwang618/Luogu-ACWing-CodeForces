#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct Point {
    long x, y;
};

Point get(long n, long a) {
    if (n == 0) return {0, 0};
    long block = 1l << 2 * n - 2, len = 1l << n - 1;
    auto p = get(n - 1, a % block);
    long x = p.x, y = p.y;

    int z = a / block;
    if (!z) return {y, x};
    else if (z == 1) return {x, y + len};
    else if (z == 2) return {x + len, y + len};
    else return {len * 2 - 1 - y, len - 1 - x};
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long n, a, b;
        scanf("%ld%ld%ld", &n, &a, &b);
        auto pa = get(n, a - 1), pb = get(n, b - 1);
        double dx = pa.x - pb.x, dy = pa.y - pb.y;
        printf("%.0lf\n", sqrt(dx * dx + dy * dy) * 10);
    }

    return 0;
}