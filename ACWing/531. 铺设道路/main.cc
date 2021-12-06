#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], res;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) res += max(a[i] - a[i - 1], 0);
    printf("%d\n", res);
    return 0;
}