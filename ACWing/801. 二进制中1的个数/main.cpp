#include <iostream>
using namespace std;

int lowbit(int x) {
    return x & -x;
}

int count1(int x) {
    int res = 0;
    while (x) {
        x -= lowbit(x);
        res++;
    }

    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        printf("%d ", count1(x));
    }

    return 0;
}