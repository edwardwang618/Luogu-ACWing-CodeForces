#include <iostream>
using namespace std;

int main() {
    int res = 0;
    for (int i = 0; i < 6; i++) {
        double x;
        cin >> x;
        if (x > 0) res++;
    }

    printf("%d positive numbers\n", res);

    return 0;
}