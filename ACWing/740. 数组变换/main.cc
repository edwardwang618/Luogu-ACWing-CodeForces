#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[20];
    for (int i = 0; i < 20; i++) cin >> a[i];
    reverse(a, a + 20);
    for (int i = 0; i < 20; i++) printf("N[%d] = %d\n", i, a[i]);
    return 0;
}