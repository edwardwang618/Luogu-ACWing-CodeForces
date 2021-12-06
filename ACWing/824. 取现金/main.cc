#include <iostream>
using namespace std;

int n;
int a[] = {1, 5, 10, 20, 100};

int main() {
    scanf("%d", &n);

    int res = 0;
    for (int i = 0; i <= 3; i++) {
        res += n % a[i + 1] / a[i];
        n -= n % a[i + 1];
    }

    res += n / 100;
    printf("%d\n", res);
    return 0;
}