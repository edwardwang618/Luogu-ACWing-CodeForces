#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int m;
int stk[N], top1 = 1, top2 = N - 1;
int sum[N], f[N];

int main() {
    f[0] = -1e9;
    scanf("%d", &m);
    while (m--) {
        char op[2];
        int x;
        scanf("%s", op);
        if (*op == 'I' || *op == 'Q') scanf("%d", &x);
        if (*op == 'I') {
            sum[top1] = sum[top1 - 1] + x;
            f[top1] = max(f[top1 - 1], sum[top1]);
            stk[top1++] = x;
        } else if (*op == 'D') {
            if (top1 > 1) top1--;
        } else if (*op == 'L') {
            if (top1 > 1) stk[top2--] = stk[--top1];
        } else if (*op == 'R') {
            if (top2 < N - 1) {
                stk[top1++] = stk[++top2];
                int top = top1 - 1;
                sum[top] = sum[top - 1] + stk[top];
                f[top] = max(f[top - 1], sum[top]);
            }
        } else printf("%d\n", f[x]);
    }

    return 0;
}