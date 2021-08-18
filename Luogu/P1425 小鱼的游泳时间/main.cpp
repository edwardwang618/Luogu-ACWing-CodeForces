#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int minute = (c - a) * 60 + d - b;
    printf("%d %d\n", minute / 60, minute % 60);
    return 0;
}