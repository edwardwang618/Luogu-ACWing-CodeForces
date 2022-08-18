#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e7;
int res[N], tmp[N];

long gcd(long a, long b) {
    return b ? gcd(b, a % b) : a;
}

bool dfs(int u, long a, long b, int depth, int max_depth) {
    if (depth == max_depth) {
        if (a == 1) {
            if (b > 1e7) return false;

            tmp[depth - 1] = (int) b;
            if (!res[depth - 1] || b < res[depth - 1]) {
                memcpy(res, tmp, depth * (sizeof(int)));
            }

            return true;
        }

        return false;
    }

    bool found = false;
    for (int i = max(u, (int) (b / a) + 1); i <= b / a * (max_depth - depth + 1); i++) {
        long nx = a * i - b, ny = b * i;
        long g = gcd(nx, ny);
        nx /= g, ny /= g;
        tmp[depth - 1] = i;
        if (dfs(i + 1, nx, ny, depth + 1, max_depth)) found = true;
    }

    return found;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);

    int g = (int) gcd(a, b);
    a /= g, b /= g;

    int max_depth = 1;
    while (!dfs(2, a, b, 1, max_depth))
        max_depth++;

    for (int i = 0; i < max_depth; i++)
        printf("%d ", res[i]);
    printf("\n");

    return 0;
}