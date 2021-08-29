#include <iostream>
using namespace std;

const int N = 1010;
int n;
int idx, mi = 0x3f3f3f3f;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x < mi) mi = x, idx = i;
    }

    printf("Minimum value: %d\nPosition: %d\n", mi, idx);

    return 0;
}