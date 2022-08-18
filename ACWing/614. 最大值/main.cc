#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int t = (a + b + abs(a - b)) / 2;
    printf("%d eh o maior\n", (t + c + abs(t - c)) / 2);
    return 0;
}