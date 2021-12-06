#include <iostream>
using namespace std;

const int N = 5e5 + 10;
int n, k;
int tr[N];

int lowbit(int x) {
    return x & -x;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i; i-= lowbit(i)) res += tr[i];
    return res;
}

void add(int s, int x) {
    for (int i = s; i <= n; i += lowbit(i)) tr[i] += x;
}

int main() {
    scanf("%d%d", &n, &k);
    while (k--) {
        char op[2];
        scanf("%s", op);
        if (*op == 'A') {
            int x;
            scanf("%d", &x);
            printf("%d\n", sum(x));
        } else {
            int s, x;
            scanf("%d%d", &s, &x);
            if (*op == 'B') add(s, x);
            else add(s, -x);
        }
    }

    return 0;
}