#include <iostream>
using namespace std;

int x[10];

int main() {
    for (int i = 0; i < 10; i++) cin >> x[i];
    for (int i = 0; i < 10; i++) printf("X[%d] = %d\n", i, x[i] <= 0 ? 1 : x[i]);
    return 0;
}