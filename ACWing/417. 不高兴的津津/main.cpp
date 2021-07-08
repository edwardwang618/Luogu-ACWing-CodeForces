#include <iostream>
using namespace std;

int main() {
    int max_time = 0, day = 0;
    for (int i = 1; i <= 7; i++) {
        int a, b;
        cin >> a >> b;
        int t = a + b;
        if (t > max_time) {
            max_time = t;
            day = i;
        }
    }

    if (max_time > 8) printf("%d\n", day);
    else printf("0\n");

    return 0;
}