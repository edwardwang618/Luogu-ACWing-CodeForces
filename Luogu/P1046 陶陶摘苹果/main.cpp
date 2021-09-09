#include <iostream>
using namespace std;

int a[10], h;

int main() {
    for (int i = 0; i < 10; i++) cin >> a[i];
    cin >> h;
    int res = 0;
    for (int i = 0; i < 10; i++) if (a[i] <= h + 30) res++;
    printf("%d\n", res);

    return 0;
}