#include <iostream>
using namespace std;

int n, x;

int main() {
    cin >> n >> x;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j) {
            if (j % 10 == x) res++;
            j /= 10;
        }
    }

    printf("%d\n", res);

    return 0;
}