#include <iostream>
using namespace std;

void divide(int n) {
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int c = 0;
            while (n % i == 0) {
                n /= i;
                c++;
            }

            printf("%d %d\n", i, c);
        }
    }

    if (n > 1) printf("%d %d\n", n, 1);
    puts("");
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;

        divide(x);
    }

    return 0;
}