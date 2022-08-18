#include <iostream>
using namespace std;

int main() {
    int x;
    while (cin >> x, x) {
        for (int i = 1; i <= x; i++)
            printf("%d ", i);
        puts("");
    }

    return 0;
}